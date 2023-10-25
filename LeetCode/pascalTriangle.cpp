#include "solution.h"

// runtime 100% 
vector<vector<int>> Solution::generate(int numRows) {
    int dp[numRows + 1][numRows + 2];
    for (int i = 0; i < numRows + 1; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    dp[0][1] = 1;

    vector<vector<int>> pascalTriangle;

    for (int i = 1; i < numRows + 1; i++) {
        vector<int> row;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            row.push_back(dp[i][j]);
        }
        dp[i][i+1] = 0;
        pascalTriangle.push_back(row);
    }

    return pascalTriangle;
}
