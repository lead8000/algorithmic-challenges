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
 