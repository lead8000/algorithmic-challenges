from typing import List

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        excepted = sorted(heights)
        count = 0
        for i in range(len(heights)):
            if heights[i] != excepted[i]:
                count += 1
        return count