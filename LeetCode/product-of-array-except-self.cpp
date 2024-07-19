class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preffixAccumulated(n), suffixAccumulated(n), answer(n);
        
        preffixAccumulated[0]  = nums[0];
        suffixAccumulated[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            preffixAccumulated[i] = preffixAccumulated[i-1] * nums[i];
            suffixAccumulated[n-i-1] = suffixAccumulated[n-i] * nums[n-i-1];
        }

        for(int i = 0; i < n; i++) {
            if (i == 0) {
                answer[i]= suffixAccumulated[1];
            }
            else if (i == n-1) {
                answer[i] = preffixAccumulated[n-2];
            }
            else {
                answer[i] = preffixAccumulated[i-1] * suffixAccumulated[i+1];
            }
        }

        return answer;
    }
};