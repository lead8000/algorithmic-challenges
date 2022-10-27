//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int maxOnes = -1;
            int index = 0;
            for (size_t row = 0; row < N; row++)
            {
                if (Mat[row][0])
                    return row;
                for (int i = 0, j = M-1, mid = (M-1)/2; i < j;)
                {
                    if (Mat[row][mid] == Mat[row][mid+1]){
                        if (Mat[row][mid])
                            j = mid; // baja
                        else
                            i = mid+1; // sube
                    }
                    else {
                        if (M-mid-1 > maxOnes){
                            maxOnes = M-mid-1;
                            index = row;
                        }
                    }
                    int tmp = i + (j-i)/2;
                    
                    if (tmp==mid)
                        break;   

                    mid = tmp;                 
                }
            }
            return index;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends