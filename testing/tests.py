import unittest
import numpy as np
from PythonWrapper import distributions

class TestGPyT(unittest.TestCase):
    def test_uniform_dist(self):
        ''' Testing that the uniform distribution generates correctly '''
        dist_length = 100000
        dist_max = 5
        dist_min = 0
        distributions.seed()
        a = distributions.uniform_dist(dist_length, dist_min, dist_max)
        self.assertEqual(len(a), dist_length, "uniform_dist: length incorrect.")
        for val in a:
            self.assertLessEqual(val, dist_max, "uniform_dist: generated value below the minimum bounds.")
            self.assertGreaterEqual(val, dist_min, "uniform_dist: generated value above the maximum bounds.")
        self.assertAlmostEqual(np.mean(a), (dist_max + dist_min) / 2, 1, "uniform_dist: generated distribution did not have the expected mean.")
    
    def test_gaussian_dist(self):
        dist_length = 100000
        dist_mu = 0
        dist_sig = 5
        a = distributions.gaussian_dist(dist_length, dist_mu, dist_sig)
        self.assertEqual(len(a), dist_length, "gaussian_dist: length incorrect.")
        self.assertAlmostEqual(np.mean(a), dist_mu, 1, "gaussian_dist: generated distribution did not have the expected mean.")
        self.assertAlmostEqual(np.std(a), dist_sig, 1, "gaussian_dist: generated distribution did not have the expected standard deviation.")
    
    def test_exponential_dist(self):
        dist_length = 100000
        dist_lambda = 0.2
        a = distributions.exponential_dist(dist_length, dist_lambda)
        self.assertEqual(len(a), dist_length, "exponential_dist: length incorrect.")
        b = np.random.exponential(dist_lambda, dist_length)
        self.assertAlmostEqual(np.mean(a), np.mean(b), 1, "exponential_dist: generated distribution did not have the expected mean.")
        self.assertAlmostEqual(np.std(a), np.std(b), 1, "exponential_dist: generated distribution did not have the expected standard deviation.")
    
    def test_bernoulli(self):
        dist_length = 100000
        dist_p = 0.5
        a = distributions.bernoulli_dist(dist_length, dist_p)
        self.assertEqual(len(a), dist_length, "bernoulli_dist: length incorrect.")
        self.assertAlmostEqual(np.mean(a), dist_p, 1, "bernoulli_dist: generated distribution did not have the expected mean.")
        dist_p = 0.2
        a = distributions.bernoulli_dist(dist_length, dist_p)
        self.assertAlmostEqual(np.mean(a), dist_p, 1, "bernoulli_dist: generated distribution did not have the expected mean.")
    
    def test_binomial(self):
        dist_length = 100000
        dist_p = 0.7
        dist_n = 50
        a = distributions.binomial_dist(dist_length, dist_p, dist_n)
        self.assertEqual(len(a), dist_length, "binomial_dist: length incorrect.")
        b = np.random.binomial(dist_n, dist_p, dist_length)
        self.assertAlmostEqual(np.mean(a), np.mean(b), 1, "binomial_dist: generated distribution did not have the expected mean.")
        dist_p = 0.2
        a = distributions.binomial_dist(dist_length, dist_p, dist_n)
        b = np.random.binomial(dist_n, dist_p, dist_length)
        self.assertAlmostEqual(np.mean(a), np.mean(b), 1, "binomial_dist: generated distribution did not have the expected mean.")
        self.assertAlmostEqual(np.std(a), np.std(b), 1, "binomial_dist: generated distribution did not have the expected standard deviation.")
    
    def test_poisson(self):
        dist_length = 100000
        dist_p = 0.7
        a = distributions.poisson_dist(dist_length, dist_p)
        self.assertEqual(len(a), dist_length, "poisson_dist: length incorrect.")
        self.assertAlmostEqual(np.mean(a), dist_p, 1, "poisson_dist: generated distribution did not have the expected mean.")
        dist_p = 2.9
        a = distributions.poisson_dist(dist_length, dist_p)
        self.assertAlmostEqual(np.mean(a), dist_p, 1, "poisson_dist: generated distribution did not have the expected mean.")


if __name__ == '__main__':
    unittest.main()