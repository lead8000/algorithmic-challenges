#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    // more efficient
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int N = nums.size();

        for (const auto& n: nums){
            freq[n] += 1;
        }
        
        vector<int> result;
        for (const auto& n: freq) {
            if (n.second > floor(N / 3)) {
                result.push_back(n.first);
            }
        }

        return result;
    }

    // vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> freq;

    //     // accumulate the freq of the elements
    //     for (const auto& n: nums){ freq[n]++; }

    //     vector<int> result;
    //     int threshold = floor(nums.size() / 3);

    //     // get the highest freq elements
    //     for (const auto& n: freq) {
    //         if (n.second > threshold) {
    //             result.push_back(n.first);
    //         }
    //     }

    //     return result;
    // }
};
