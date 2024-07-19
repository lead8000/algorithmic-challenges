class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sumKSubarr = 0;
        for(int i = 0; i < k; i++) {
            sumKSubarr += nums[i];
        }

        int maxSum = sumKSubarr;
        for(int i = k; i < nums.size(); i++) {
            sumKSubarr += (nums[i]-nums[i-k]);
            maxSum = max(maxSum, sumKSubarr);
        }

        return (double)maxSum/(double)k;
    }
};