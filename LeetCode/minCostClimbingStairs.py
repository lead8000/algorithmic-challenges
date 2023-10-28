from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        N = len(cost)

        dp = [0 for _ in range(N+2)]
        dp[1] = cost[0]
        dp[2] = cost[1]

        for i in range(3, N+2):
            if i-1 != N:
                dp[i] = cost[i-1] 

            dp[i] += min(dp[i-1], dp[i-2])

        return dp[N+1]
        
        