#include "solution.h"

int Solution::maxProfit(vector<int>& prices) {
    int minn = prices[0], maxGain = 0;

    for (int i = 1; i < prices.size(); i++) {
        maxGain = max(maxGain, prices[i] - minn);
        minn = min(minn, prices[i]);
    }

    return maxGain;   
}