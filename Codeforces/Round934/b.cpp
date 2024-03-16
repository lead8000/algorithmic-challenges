#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> seq, int n, int k)
{
    vector<int> seq1, seq2;
    for (int i = 0; i < n; i++)
    {
        seq1.push_back(seq[i]);   
        seq2.push_back(seq[i+n]);
    }

    sort(seq1.begin(), seq1.end());
    sort(seq2.begin(), seq2.end());

    vector<int> res1, res2;
    vector<int> uniques;

    for (int i = 0, kk = 0; i < n && kk < k; i++)
    {
        if (i < n-1 && seq1[i] == seq1[i+1]) {
            res1.push_back(seq1[i]);
            res1.push_back(seq1[i]);
            kk+=2;
            i++;
        }
        else {
            uniques.push_back(seq1[i]);
        }
    }

    for (int i = 0, kk = 0; i < n-1 && kk < k; i++)
    {
        if (seq2[i] == seq2[i+1]) {
            res2.push_back(seq2[i]);
            res2.push_back(seq2[i]);
            kk+=2;
            i++;
        }
    }

    for (int i = 0, kk = res1.size(); kk < k; i++, kk++)
    {
        res1.push_back(uniques[i]);
        res2.push_back(uniques[i]);
    }

    for (int i = 0; i < k; i++) {
        cout<<res1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < k; i++) {
        cout<<res2[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int t, n, k;
    cin>>t;
    
    while (t--)
    {
        cin>>n>>k;
        vector<int> v(2*n, 0);

        for (int i = 0; i < 2*n; i++) {
            cin>>v[i];
        }
        
        solve(v, n, 2*k);
    }

    return 0;
}