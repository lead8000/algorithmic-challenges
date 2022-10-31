//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        string input = "";
        for (size_t i = 0; i < s.size(); i++)
        {
            input += s[i];
        }
        
        vector<string> result(0, "");

        if (input.size()<4 || input.size()>12)
            return result;

        string A = "";
        for (size_t i = 0; i < 3 && i < input.size(); i++)
        {
            A += input[i];
            if (A.size() > 1 && A[0] == '0')
                    break;
                
            string B = "";
            for (size_t j = i+1; j < i+4 && j < input.size(); j++)
            {
                B += input[j];
                if (B.size() > 1 && B[0] == '0')
                    break;
                
                string C = "";
                for (size_t k = j+1; k < j+4 && k < input.size(); k++)
                {
                    C += input[k];
                    if (C.size() > 1 && C[0] == '0')
                        break;
                
                    string D = "";
                    for (size_t h = k+1; h < input.size(); h++)
                    {
                        D += input[h];
                        if (D.size() > 1 && D[0] == '0'){
                            D = "";
                            break;
                        }
                    }
                    if (D == "")
                        continue;
                    if (stoi(A)<=255 && stoi(B)<=255 && stoi(C)<=255 && stoi(D)<=255)
                        result.push_back(A+"."+B+"."+C+"."+D);
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends