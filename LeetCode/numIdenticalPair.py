from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        freq = {}
        amount = 0
        for n in nums:
            if not n in freq:
                freq[n] = 1
            else:
                amount = amount + freq[n]
                freq[n] = freq[n] + 1

        return int(amount)