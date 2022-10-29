//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        int distinct = 0;
        map<int, int> dict;
        vector<int> result;

        for (size_t i = 0; i < n; i++)
        {
            if (dict[A[i]] == 0)
                distinct++;
            dict[A[i]]++;
            if (i >= k){
                dict[A[i-k]]--;
                if (!dict[A[i-k]])
                    distinct--;                    
            }
            if (i >= k-1)
                result.push_back(distinct);
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends