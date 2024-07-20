class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> maskNums1(2001), maskNums2(2001);

        for(auto x: nums1) {
            maskNums1[x+1000]=true;
        }

        vector<int> nums2_result;
        for(auto y: nums2) {
            if (!maskNums1[y+1000] && !maskNums2[y+1000]) {
                nums2_result.push_back(y);
            }
            maskNums2[y+1000]=true;
        }

        vector<int> nums1_result;
        for (auto x: nums1) {
            if (!maskNums2[x+1000]) {
                nums1_result.push_back(x);
                maskNums2[x+1000]=true;
            }
        }

        return {nums1_result, nums2_result};
    }
};