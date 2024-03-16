#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> a, int n)
{
    int turns = (int)ceil((double)n/2);

    map<int, int> dict;
    for (int i = 0; i < n; i++) {
        dict[a[i]] += 1;
    }

    for (int i = 0; i < turns; i++) {
        bool yet = false;
        for (int j = 0; j <= i && dict[i] != 0; j++) {
            if (dict[j] - i > 0) {
                yet = true;
                break;
            }
        }
        if (!yet) {
            cout<<i<<endl;
            return;
        }
    }
    cout<<turns<<endl;   
}

int main()
{
    int t, n;
    cin>>t;

    while (t--)
    {
        cin>>n;
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }

        solve(v, n);
    }

    return 0;
}