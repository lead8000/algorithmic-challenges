//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        for (size_t i=0, j=n-1, mid=(n-1)/2; i < j;)
        {
            if (arr[mid] == arr[mid+1])
            {
                if ((mid-i+1)%2==0)
                    j = mid-1;
                else 
                    i = mid+2;
            }
            else {
                if ((mid-i+1)%2==1)
                    j = mid;
                else 
                    i = mid+1;
            }
            mid = i+(j-i)/2;

            if (i == j)
                return arr[i];
        }
        
        return n == 1? arr[0]: -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends