#include "solution.h"

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int curr_min = 0, amountIncrement = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > curr_min) {
                curr_min = nums[i]+1;
            }
            else if (nums[i] == curr_min) {
                curr_min++;
            } else {
                amountIncrement += curr_min-nums[i];
                curr_min++;
            }
        }

        return amountIncrement;
    }
};