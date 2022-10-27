//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {

        bitset<32> bset_N(N);
        int result = 0;

        for (int i = 0; i < 32; i++)
        {
            if (i >= L-1 && i <= R-1)
                bset_N[i] = !bset_N[i];
            result += bset_N[i] * pow(2, i);   
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends