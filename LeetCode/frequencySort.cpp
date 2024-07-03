#include "solution.h"

string Solution::frequencySort(string s) {
    map<char, int> freq;
    for(char c: s) {
        freq[c]++;
    }
    
    vector<pair<int,char>> vfreq;
    for(auto x: freq) {
        vfreq.push_back({-1*x.second,x.first});
    }
    sort(vfreq.begin(), vfreq.end());

    string sSorted = "";
    for(auto x: vfreq) {
        for (int i = 0; i < -1*x.first; i++) {
            sSorted += x.second;
        }
    }

    return sSorted;
}