//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k
    void reverseInGroups(vector<long long>& arr, int n, int k){
        for (size_t i = 0; i < arr.size();i+=k){
            aux(arr, i, i + k);
        }        
    }

    void aux(vector<long long>& arr, int i, int j)
    {
        if (j > arr.size())
            j = arr.size();

        for (size_t ii = i; ii < i + (j - i) / 2; ii++)
        {
            long long tmp = arr[ii];
            arr[ii] = arr[j - 1 - (ii - i)];
            arr[j - 1 - (ii - i)] = tmp;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends