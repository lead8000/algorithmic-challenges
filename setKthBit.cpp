//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setKthBit(int N, int K)
    {
        bitset<32> bset_N(N);
        bset_N[K] = 1;
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            result+=bset_N[i]*pow(2,i);
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
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends