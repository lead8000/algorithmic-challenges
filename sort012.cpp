//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int amount0 = 0, amount1 = 0, amount2 = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (a[i] == 0)
                amount0++;
            else if (a[i] == 1)
                amount1++;
            else if (a[i] == 2)
                amount2++;
        }
        
        int j = 0;

        for (size_t i = 0; i < amount0; i++, j++)
        {
            a[j] = 0;
        }

        for (size_t i = 0; i < amount1; i++, j++)
        {
            a[j] = 1;
        }

        for (size_t i = 0; i < amount2; i++, j++)
        {
            a[j] = 2;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends