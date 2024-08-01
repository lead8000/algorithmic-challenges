class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;

        for(int i = 0; i < k; i++) {
            heap.push(-nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            if (-heap.top() < nums[i]) {
                heap.pop();
                heap.push(-nums[i]);
            }
        }
        return -heap.top();
    }
};