//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    int start = 0;
    map<char, int> dict;
    vector<bool> mask(26, false);
    int lenSubstr = 0;
    int maxDist = -1;

    for (int i = 0; i < S.size(); i++)
    {
        if (mask[(int)S[i]%26]){
            int tmp = dict[(int)S[i]%26];
            for (int j = tmp; j >= start ; j--)
            {
                mask[(int)S[j]%26] = false;
                dict[(int)S[j]%26] = -1;
            }
            start = tmp+1;
        }
        mask[(int)S[i]%26] = true;
        dict[(int)S[i]%26] = i;
        
        if (i-start+1 > maxDist)
            maxDist = i-start+1;
    }
    
    return maxDist;
}