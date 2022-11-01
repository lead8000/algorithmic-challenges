//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
        sort(arr, arr+n);
        int result = 0;

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                if (search_binary(arr, j+1, n-1, arr[i] + arr[j]))
                    result++;
            }
        }
        return result;
	}

    bool search_binary(int arr[], int l, int r, int number){
        for (int mid = l + (r-l)/2;l<=r; mid = l + (r-l)/2)
        {
            if (arr[mid] == number || arr[l] == number || arr[r] == number)
                return true;
            if (arr[mid] < number){
                l = mid;
            } else if (arr[mid] > number) {
                r = mid;
            } 
            if (mid == l + (r-l)/2)
                break;
        }
        return false;
    }
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends