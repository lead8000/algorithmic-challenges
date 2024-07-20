class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        for(int i = 1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
        }

        nums.insert(nums.begin(), 0);
        for(int i = 1; i<nums.size(); i++) {
            if (nums[i-1] == nums[nums.size()-1]-nums[i])
                return i-1;
        }

        return -1;
    }
};