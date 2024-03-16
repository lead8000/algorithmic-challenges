#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin>>t;
    
    while (t--)
    {
        cin>>n>>k;

        if (k < n-1)
            cout<<n<<endl;
        else
            cout<<1<<endl;
    }

    return 0;
}