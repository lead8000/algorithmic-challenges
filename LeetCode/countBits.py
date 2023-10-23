from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0 for _ in range(n+1)]

        for i in range(1, n+1):
            ans[i] = ans[i//2] + i%2

        return ans
