#include "solution.h"

int Solution::minOperations(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());
    vector<int> vi(s.begin(), s.end());

    int p1 = 0, p2 = 0, maxSize = -1, N = nums.size(), M = vi.size();
    while (p1 <= p2 && p2 < M)
    {
        if (vi[p2] - vi[p1] <= N - 1) {
            maxSize = max(maxSize, p2 - p1 + 1);
            p2++;
        }
        else p1++;
    }

    return nums.size() - maxSize;
}
