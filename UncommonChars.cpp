//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            vector<int> mask(256, 0);
            for (int i = 0; A[i] != '\0'; i++)
                mask[A[i]] = 1;

            for (int i = 0; B[i] != '\0'; i++)
            {
                if (mask[B[i]] == 1)
                    mask[B[i]] = 2;
                else if (mask[B[i]] != 2)
                    mask[B[i]] = 3;
            }
            char result[256];
            int len = 0;
            for (int i = 0; i < 256; i++)
            {
                if (mask[i] == 1 || mask[i] == 3)
                    result[len++] = (char)i;
            }

            string output = "";
            for (int i = 0; i < len; i++)
                output += result[i];
            
            return output == "" ? "-1" : output;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends