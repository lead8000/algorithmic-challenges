class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> accumLeftToRight(n+2), accumRightToLeft(n+2);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                accumLeftToRight[i+1] += accumLeftToRight[i] + 1;
            if (nums[n-i-1] == 1)
                accumRightToLeft[n-i] += accumRightToLeft[n-i+1] + 1;
        }

        int maxAmountOnes = 0;
        for (int i = 0; i < n; i++) {
            maxAmountOnes = max(maxAmountOnes, accumLeftToRight[i]+accumRightToLeft[i+2]);
        }

        return maxAmountOnes;
    }
};