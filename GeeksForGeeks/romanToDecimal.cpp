//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        map<char, int> dict;
        dict['I'] = 1; 
        dict['V'] = 5; 
        dict['X'] = 10; 
        dict['L'] = 50; 
        dict['C'] = 100; 
        dict['D'] = 500; 
        dict['M'] = 1000;

        int result = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (i+1<str.size() && dict[str[i]] < dict[str[i+1]])
                result -= dict[str[i]];
            else 
                result += dict[str[i]];
        }
        return result;   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends