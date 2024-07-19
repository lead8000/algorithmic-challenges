class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroHeadPtr = 0;
        while (zeroHeadPtr < nums.size() && nums[zeroHeadPtr] != 0) { zeroHeadPtr++; }

        if (zeroHeadPtr == nums.size())
            return;
        int amountZeros = 1;

        for (int i = zeroHeadPtr+1; zeroHeadPtr + amountZeros < nums.size(); i++) {
            if (nums[i] == 0) {
                amountZeros++;
            }
            else {
                nums[zeroHeadPtr++] = nums[i];
                nums[i] = 0;
            }
        }
    }
};