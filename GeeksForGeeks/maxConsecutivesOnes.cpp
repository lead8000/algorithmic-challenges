//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        bitset<32> bset(N);
        int _max = -1;

        for (size_t i = 0; i < 32; i++)
        {
            int count = 0;
            while (i<32 && bset[i])
            {
                count++;
                i++;   
            }
            _max = max(_max, count);
        }
        
        return _max;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends