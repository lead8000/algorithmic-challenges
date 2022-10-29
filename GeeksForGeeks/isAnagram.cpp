//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if (a.size() != b.size())
            return false;

        map<char, int> dict;

        for (size_t i = 0; i < a.size(); i++)
        {
            dict[a[i]] += 1;
        }
        
        for (size_t i = 0; i < a.size(); i++)
        {
            dict[b[i]] -= 1;
        }

        for (size_t i = 0; i < a.size(); i++)
        {
            if (dict[a[i]] != 0 || dict[b[i]] != 0){
                // cout<<'a[i]:'<<a[i]<<'--'<<dict[a[i]]<<endl;
                // cout<<'b[i]:'<<b[i]<<'--'<<dict[b[i]]<<endl;
                return false; 
            }
        }
        
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends