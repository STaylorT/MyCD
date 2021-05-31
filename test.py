import unittest

from mycd import Parser

class TestMyCD(unittest.TestCase):
    def test_case1(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/","abc")
        self.assertEqual(result, "/abc")

    def test_case2(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","ghi")
        self.assertEqual(result, "/abc/def/ghi")
    
    def test_case3(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","..")
        self.assertEqual(result, "/abc")

    def test_case4(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","/abc")
        self.assertEqual(result, "/abc")

    def test_case5(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","/abc/klm")
        self.assertEqual(result, "/abc/klm")
    
    def test_case6(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","../..")
        self.assertEqual(result, "/")
    
    def test_case7(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","../../..")
        self.assertEqual(result, "/")

    def test_case8(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def",".")
        self.assertEqual(result, "/abc/def")

    def test_case9(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","..klm")
        self.assertEqual(result, "No such file or directory.")
    
    def test_case10(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","//////")
        self.assertEqual(result, "/")

    def test_case11(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def",".......")
        self.assertEqual(result, "No such file or directory.")

    def test_case12(self):
        """
        Test to make sure output directory correct
        """
        result = Parser("/abc/def","../gh///../klm//.")
        self.assertEqual(result, "/abc/klm")

if __name__ == '__main__':
    unittest.main()
