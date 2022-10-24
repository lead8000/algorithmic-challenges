//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int ini = 0;
        long long s2 = 0;
        vector<int> result;

        for (size_t i = 0; i < n; i++)
        {
            s2 += arr[i];
            
            while (s2 > s && ini <= i){
                s2-=arr[ini];
                ini++;
            }

            if (s2 == s && ini <= i){
                result.push_back(ini + 1);
                result.push_back(i + 1);
                return result;
            }
        }
        
        result.push_back(-1);
        return result;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends