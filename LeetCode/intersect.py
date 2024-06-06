from typing import List

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        amount_num1 = [0 for _ in range(1001)]
        amount_num2 = [0 for _ in range(1001)]

        i = 0
        while i < len(nums1) or i < len(nums2):
            if i < len(nums1):
                amount_num1[nums1[i]] += 1
            if i < len(nums2):
                amount_num2[nums2[i]] += 1
            i += 1

        result = []
        for num in range(1001): 
            minn =  min(amount_num1[num], amount_num2[num])
            while minn > 0:
                result.append(num)
                minn -= 1
            
        return result

print(Solution().intersect([1,2,2,1], [2,2]))