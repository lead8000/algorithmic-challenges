//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to nextLevel even bits.
    unsigned int swapBits(unsigned int n)
    {
        bitset<32> bset(n);
        unsigned int result = 0;
        for (size_t i = 0; i < 32; i+=2)
        {
            result += bset[i] * pow(2,i+1);   
            result += bset[i+1] * pow(2,i);  
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } DrivnextLevel