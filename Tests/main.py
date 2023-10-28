import sys
sys.path.append('..')

from LeetCode.countVowelPermutation import Solution

if __name__ == '__main__':
    solver = Solution()
    print(solver.countVowelPermutation(10**4))    
