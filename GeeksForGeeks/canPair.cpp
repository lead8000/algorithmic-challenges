//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {

        if (nums.size()%2 == 1)
            return false;

        map<int, int> dict;
        int amount_pairs = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (dict[nums[i]%k]){
                amount_pairs++;
                dict[nums[i]%k]--;
            } else if (nums[i]%k == 0)
                dict[nums[i]%k]++;
            else
                dict[k-nums[i]%k]++;
        }
        
        return amount_pairs == nums.size()/2;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends