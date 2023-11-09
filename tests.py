import unittest
import numpy as np
import distributions

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
        self.assertAlmostEqual(np.mean(a), dist_mu, 1, "gaussian_dist: generated distribution did not have the expected mean.")
        self.assertAlmostEqual(np.std(a), dist_mu, 1, "gaussian_dist: generated distribution did not have the expected standard deviation.")


if __name__ == '__main__':
    unittest.main()