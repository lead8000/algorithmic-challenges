#include "solution.h"

vector<int> Solution::sortByBits(vector<int>& arr) {
    vector<pair<int,int>> bits;

    for (int i = 0, amountBits, number; i < arr.size(); i++) {
        amountBits = 0;
        number = arr[i];
        while (number > 0) {
            amountBits += number % 2;
            number /= 2;
        }
        bits.push_back(pair<int,int>(amountBits, arr[i]));
    }
    
    sort(bits.begin(), bits.end());

    transform(bits.begin(), bits.end(), arr.begin(),
        [](const std::pair<int, int>& p) { return p.second; });

    return arr;
}