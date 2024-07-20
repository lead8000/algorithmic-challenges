class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        unordered_set<int> nums;
        for(auto x: arr) {
            freq[x]++;
            nums.insert(x);
        }

        unordered_set<int> unique_freq;
        for(auto y: nums) {
            if (unique_freq.find(freq[y]) == unique_freq.end()) {
                unique_freq.insert(freq[y]);
            }
            else {
                return false;
            }
        }

        return true;
    }
};