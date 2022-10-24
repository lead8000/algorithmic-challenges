//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    for (int i = 0; i < s.size(); i++)
    {
        int count = 0;  
        for (int j = i, count = 0; s[j] == x[count];)
        {
            j++;
            count++;
            if (count == x.size())
                return j - count;
            if (j == s.size())
                return -1;
        }
    }
    return -1;
}