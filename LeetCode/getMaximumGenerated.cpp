#include "solution.h"

int getMaximumGenerated(int n) {
    int maxx = 0;
    vector<int> dp(n+1, 0);
    if (n > 0) {
        dp[1] = 1;
        maxx = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0)
            dp[i] = dp[i/2];
        else
            dp[i] = dp[i/2] + dp[i/2 + 1]; 
        maxx = max(maxx, dp[i]);
    }

    return maxx;
}
