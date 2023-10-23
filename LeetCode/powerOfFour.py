import math

class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n < 1:
            return False

        log = math.log(n, 4)
        return abs(int(log) - log) < 1e-5
