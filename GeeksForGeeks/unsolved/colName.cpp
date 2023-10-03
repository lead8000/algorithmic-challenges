// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution{
    private:
    ll aux(int len)
    {
        ll result = 0;
        for (int i = 0; i < len; i++)
        {
            result += (ll)pow((ll)26,(ll)i+1);
        }
        return result;
    }
    
    public:
    string colName(long long int n)
    {
        int len = ceil(log(n) / log((ll)26));

        string result = "";
        for (int i = 0; i < len; i++)
        {
            ll amount = (ll)pow((ll)26, len-1-i);
            int c = n / amount;

            if (n - c * amount < aux(len-2-i)) {
                c--;
            }
            n -= c * amount;

            result += (char)('A' - 1 + c);
        }

        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends