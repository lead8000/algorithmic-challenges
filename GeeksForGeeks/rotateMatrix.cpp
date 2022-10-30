//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {

        vector<vector<int>> matrix(M, vector<int> (N, 0));
        int amount_cells = 0;

        for (size_t i = 0, j = 0; i < M && j < N; i++, j++)
        {
            if (i == M/2 && j == N/2 && amount_cells != N*M){
                matrix[i][j] = Mat[i][j];
                amount_cells++;
            } 
            if (i == M/2 && amount_cells != N*M){
                for (size_t k = 0; j+k < N-j; k++)
                {
                    matrix[i][j+k] = Mat[i][j+k];
                    amount_cells++;
                }
            }
            if (j == N/2 && amount_cells != N*M){
                for (size_t k = 0; i+k < M-i; k++)
                {
                    matrix[i+k][j] = Mat[i+k][j];
                    amount_cells++;
                }
            }
            if (amount_cells == M*N){
                break;
            }
            // a la derecha
            for (size_t k = 0; j+k+1 < N-j; k++)
            {
                matrix[i][j+k+1] = Mat[i][j+k];
                amount_cells++;
            }
            // abajo
            for (size_t k = 0; i+k+1 < M-i; k++)
            {
                matrix[i+k+1][N-1-j] = Mat[i+k][N-1-j];  
                amount_cells++;
            }

            // izquierda
            for (int k = 0; N-1-j-k-1 >= j; k++)
            {
                matrix[M-1-i][N-1-j-k-1] = Mat[M-1-i][N-1-j-k];
                amount_cells++;
                if (N-1-j-k-1 == 0)
                    break;
            }

            // arriba
            for (size_t k = 0; M-1-i-k-1 >= i; k++)
            {
                matrix[M-1-i-k-1][j] = Mat[M-1-i-k][j];
                amount_cells++;
                if (M-1-i-k-1 == 0)
                    break;
            }
        }

        return matrix;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends