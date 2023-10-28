class Solution:
    def tribonacci(self, n: int) -> int:
        n_0, n_1, n_2 = 0, 1, 1

        for _ in range(2, n):
            n_3 = n_0 + n_1 + n_2

            n_0 = n_1
            n_1 = n_2
            n_2 = n_3

        return n_2 if n != 0 else 0