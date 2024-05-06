from primery_judge import is_prime_v3 as is_prime
import unittest


class PrimeTest(unittest.TestCase):
    def test_is_prime_ok(self):
        for i in [2,3,5,7,11,13]:
            self.assertTrue(is_prime(i))
    
    def test_is_prime_no(self):
        for i in [1,4,6,8,9,10,12]:
            self.assertFalse(is_prime(i))

    def test_is_prime_raise_type_error(self):
        with self.assertRaises(TypeError):
            is_prime()


if __name__ == '__main__':
    unittest.main()
    