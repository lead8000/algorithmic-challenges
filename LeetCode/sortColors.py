from typing import List 

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        amount_0, amount_1, amount_2 = 0, 0, 0
        for num in nums:
            if num == 0:
                amount_0 += 1
            elif num == 1:
                amount_1 += 1
            else:
                amount_2 += 1
        
        for i in range(len(nums)):
            if amount_0 > 0:
                nums[i] = 0
                amount_0 -= 1
            elif amount_1 > 0:
                nums[i] = 1
                amount_1 -= 1
            else:
                nums[i] = 2
                amount_2 -= 1