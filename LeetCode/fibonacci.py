class Solution:
    def fib(self, n: int) -> int:
        if n == 0: return 0

        last_state = 1
        curr_state = 1

        for _ in range(2, n):
            tmp = curr_state
            curr_state += last_state
            last_state = tmp
        
        return curr_state