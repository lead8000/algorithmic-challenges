//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key)
    {
        for (size_t i = l, j = h, mid = i + (j - i) / 2;; mid = i + (j - i) / 2)
        {
            if (A[i] == key)
                return i;
            if (A[mid] == key)
                return mid;
            if (A[j] == key)
                return j;

            if (A[i] > A[j])
            {
                if (A[i] < A[mid])
                {
                    if (key >= A[i] && key <= A[mid])
                        j = mid;
                    else
                        i = mid;
                }
                else
                {
                    if (key >= A[mid] && key <= A[j])
                        i = mid;
                    else
                        j = mid;
                }
            }
            else
            {
                if (A[mid] > key)
                    j = mid;
                else if (A[mid] < key)
                    i = mid;
            }
            
            if (mid == i + (j-i)/2)
                break;
        }
        
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends