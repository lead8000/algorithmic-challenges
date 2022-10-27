//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        vector<int> rotate(int n, int d)
        {
            d %= 16;
            bitset<16> bsetN(n);
            int rotate_left = 0, rotate_right = 0;

            for (int i = 0; i < 16; i++)
            {
                rotate_left += bsetN[i] * pow(2, ((i+d) % 16));
                rotate_right += bsetN[i] * pow(2, ((i-d+16) % 16));
            }

            vector<int> result = {rotate_left, rotate_right};
            return result;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends