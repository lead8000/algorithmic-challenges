//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string longestCommonPrefix (string arr[], int N)
    {
        int minLen = arr[0].length();
        
        for(int i = 1; i < N; i++) {
            int j = 0;
            for(; j < arr[i].length() && j < arr[0].length(); j++) {
                if(arr[i][j] != arr[0][j])
                    break;
            }
            minLen = min(minLen, j);
        }
        
        if(!minLen) return "-1";
        
        string solve = "";
        for(int i = 0; i < minLen; i++)
            solve += arr[0][i];
        return solve;
    }
};



//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends