import sys
sys.path.append('..')

from LeetCode.numIdenticalPair import Solution

if __name__ == '__main__':
    solver = Solution()
    nums = [1,1,1,1]
    print(solver.numIdenticalPairs(nums))