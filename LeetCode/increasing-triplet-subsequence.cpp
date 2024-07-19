#include "solution.h"

bool Solution::increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3)  return false;

    int i = 0;
    for(;i+1 < nums.size() && nums[i] >= nums[i+1]; i++) {  }
    int j = i+1;

    int ii = -1;

    for(int k=j+1; k<nums.size(); k++){
        if (nums[j] < nums[k]) {
            return true;
        }
        else if (nums[i] < nums[k] && nums[k] < nums[j]) {
            j = k;
        }
        else if (nums[k] <= nums[i]) {
            if (ii != -1) {
                i = ii;
                j = k;
                ii = -1;
            }
            else if (nums[k] != nums[i]) {
                ii = k;
            }
        }
    }

    return false;
}
