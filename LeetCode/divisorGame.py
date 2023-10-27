class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [False for _ in range(n+1)]

        for i in range(2, n+1):
            win = False
            for j in range(1, i):
                if i % j == 0:
                    win |= not dp[i-j]
            dp[i] = win

        return dp[n]