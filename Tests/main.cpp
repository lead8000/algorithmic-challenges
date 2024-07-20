#include <iostream>
#include "../LeetCode/solution.h"

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> dp(arr.size()+1);
    dp[1] = arr[0];

    for (int i = 1, kk = k, a, b, a_k; i < arr.size(); i++) {
        a = dp[i] - dp[i-1];
        a_k = dp[i-k] - dp[i-k-1];
        b = arr[i];

        if (a < b) {
            // for (int j = i; j > 0 && arr[j-1] < arr[j] && kk > 0; j--) {
            //     arr[j-1] = arr[j];
            // }
        }
        else if (a > b) {
            if (kk > 0) {
                dp[i+1] = dp[i] + a;
                kk--;
            }
            else {
                if (a_k > b && arr[i-k] != arr[i-1]) {
                    dp[i+1] = dp[i] + arr[i-k];
                }
                else {
                    kk = k;
                }
            }
        }
    }
    return 0;
} 

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> accumLeftToRight(n+2), accumRightToLeft(n+2);

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1)
            accumLeftToRight[i+1] += accumLeftToRight[i] + 1;
        if (nums[n-i-1] == 1)
            accumRightToLeft[n-i] += accumRightToLeft[n-i+1] + 1;
    }

    // for (auto x: accumLeftToRight) cout<<x<<" ";
    // cout<<endl;
    for (auto x: accumRightToLeft) cout<<x<<" ";
    cout<<endl;

    int maxAmountOnes = 0;
    for (int i = 0; i < n; i++) {
        maxAmountOnes = max(maxAmountOnes, accumLeftToRight[i]+accumRightToLeft[i+2]);
    }

    return maxAmountOnes;
}

int main() {
    vector<int> nums = {1,0,1,1};
    cout<<longestSubarray(nums)<<endl;
    return 0;
}