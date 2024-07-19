class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int amountPairs=0; // accumulate the result
        int lPtr=0, rPtr=nums.size()-1;
        while (lPtr < rPtr) {
            if (nums[lPtr] + nums[rPtr] == k) {
                amountPairs++;
                lPtr++;
                rPtr--;
            }
            else if (nums[lPtr] + nums[rPtr] < k) {
                lPtr++;
            }
            else {
                rPtr--;
            }
            if (2 * nums[lPtr] > k) break;
        }

        return amountPairs;
    }
};