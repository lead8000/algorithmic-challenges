#include "solution.h"

// Inefficient solution
// int Solution::maxArea(vector<int>& height) {
//     int maxArea = 0;

//     for(int i = 0; i < height.size(); i++) {
//         for(int j = i+1; j < height.size(); j++) {
//             maxArea = max(maxArea, (j-i) * min(height[i], height[j]));
//         }
//     }

//     return maxArea;
// }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int Solution::maxArea(vector<int>& height) {

    int maxArea = 0;

    int lPtr=0, rPtr=height.size()-1;

    while (lPtr != rPtr) {
        maxArea = max(maxArea, (rPtr-lPtr)*min(height[lPtr], height[rPtr]));
        if (height[lPtr] < height[rPtr]) {
            lPtr++;
        }
        else {
            rPtr--;
        }
    }

    return maxArea;
}