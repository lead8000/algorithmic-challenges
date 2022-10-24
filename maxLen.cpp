//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
        int maxLen(vector<int> &A, int n)
        {
            vector<int> v;
            v.push_back(A[0]);

            for (int i = 1; i < n; i++)
            {
                v.push_back(v[i - 1] + A[i]);
            }

            map<int, vector<int>> dict;

            int max = -1;

            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                    max = i+1;

                dict[v[i]].push_back(i);
            }

            for (int i = 0; i < n; i++)
            {
                if (dict[v[i]][dict[v[i]].size() - 1] - dict[v[i]][0] > max)
                    max = dict[v[i]][dict[v[i]].size() - 1] - dict[v[i]][0];
            }

            return max;
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends