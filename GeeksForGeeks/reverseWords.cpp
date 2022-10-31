//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string> pil;
        for (size_t i = 0; i < S.size(); i++)
        {
            string tmp = "";
            while (i < S.size() && S[i] != '.')
            {
                tmp += S[i++];
            }
            pil.push(tmp);
        }
        if (S[S.size()-1] == '.')
            pil.push("");
        string result = pil.top();
        pil.pop();
        while (pil.size() > 0)
        {
            result += "." + pil.top();
            pil.pop();
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends