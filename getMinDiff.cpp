//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {

        sort(arr, arr+n);
 
        int shortest = arr[0], tallest = arr[n-1], minDiff = tallest - shortest;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - k < 0)
                continue;

            shortest = min(arr[0] + k, arr[i] - k);
            tallest = max(arr[i-1] + k, arr[n-1] - k);
            minDiff = min(minDiff, tallest - shortest);       
        }
        
        return minDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends