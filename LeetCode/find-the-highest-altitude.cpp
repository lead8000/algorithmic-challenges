class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        gain.insert(gain.begin(), 0);
        
        int maxAltitude = 0;
        for (int i = 0; i < gain.size()-1; i++) {
            gain[i+1] += gain[i];
            maxAltitude = max(maxAltitude, gain[i+1]);
        }
        return maxAltitude;
    }
};