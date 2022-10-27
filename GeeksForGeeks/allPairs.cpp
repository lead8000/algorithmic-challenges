//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<int> vA;
        vector<pair<int,int>> solve;

        for (int i = 0; i < N; i++){
           vA.push_back(A[i]);
        }
        sort(vA.begin(), vA.end());

        map<int, int> dict;
        for (int i = 0; i < M; i++)
            dict[B[i]] += 1;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < dict[X - vA[i]]; j++)
            {
                pair<int,int> tmp;
                tmp.first = vA[i];
                tmp.second = X - vA[i];
                solve.push_back(tmp);
            }
        }
        

        return solve;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends