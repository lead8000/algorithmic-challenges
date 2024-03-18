#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> a, int n)
{
    int turns = (int)ceil((double)n/2);

    map<int, int> dict;
    for (int i = 0; i < n; i++) {
        dict[a[i]] += 1;
    }

    bool got_first = false;
    int max = 0;
    for (int i = 0; i < turns; i++) {
        if (dict[i] == 0) {
            break;
        }
        if (dict[i] == 1) {
            if (!got_first) 
                got_first = true;
            else
                break;
        }
        max++;
    }
    cout<<max<<endl;   
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