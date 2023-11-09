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
        self.assertAlmostEqual(np.mean(a), (dist_max + dist_min) / 2)


if __name__ == '__main__':
    unittest.main()