//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int jumps = 0, top = arr[0];

        for (int i = 1; i < n; i++, jumps++)
        {
            int max = -1;
            for (; i <= top && i < n; i++)
            {
                if (i + arr[i] > max)
                    max = i + arr[i];
            }
            if (max == -1)
                break;
            top = max;
        }

        return top < n - 1 ? -1 : jumps;       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends