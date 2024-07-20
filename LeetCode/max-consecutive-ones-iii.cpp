class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int currAmountOnes = 0, currAmountZeros = 0, maxAmountOnes = 0;
        int lazyPtr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currAmountOnes++;
                maxAmountOnes = max(maxAmountOnes, currAmountOnes);
            }
            else {
                if (currAmountZeros < k) {
                    currAmountOnes++;
                    maxAmountOnes = max(maxAmountOnes, currAmountOnes);
                }
                else {
                    while (nums[lazyPtr++] == 1) { 
                        currAmountOnes--;
                    }
                }
                currAmountZeros++;
            }
        }

        return maxAmountOnes;
    }
};