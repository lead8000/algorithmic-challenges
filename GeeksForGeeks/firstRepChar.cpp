//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    vector<bool> mask(256, false);
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (mask[s[i]]){
            string result = "";
            result += s[i];
            return result;
        }
        mask[s[i]] = true;
    }
    
    return "-1";
}