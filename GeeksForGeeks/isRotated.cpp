//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if (str1.size()!=str2.size())
            return false;
        int len = str1.size();
        int asserts = 0;
        for (size_t i = 0; i < str1.size(); i++)
        {
            if (str1[i] == str2[(i+2)%len])
                asserts++;      
        }
        if (asserts == len)
            return true;
        asserts = 0;
        for (size_t i = 0; i < str1.size(); i++)
        {
            if (str1[i] == str2[(len-2+i)%len])
                asserts++;      
        }
        return asserts == len;
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends