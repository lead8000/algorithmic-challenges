#include "solution.h"

int Solution::climbStairs(int n) {
    int last_step = 0, curr_step = 1, next_step;
    
    for (int i = 0; i < n; i++) {
        next_step = curr_step + last_step;
        last_step = curr_step;
        curr_step = next_step;
    }

    return curr_step;
}