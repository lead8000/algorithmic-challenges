#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    s += "$";

    int n = s.size();

    vector<pair<char, int>> cp;
    for (int i = 0; i < n; i++)
    {
        cp.push_back({s[i], i});
    }
    sort(cp.begin(), cp.end());

    vector<pair<int,int>> pc(n);
    pc[0].second=1;
    pc[0].first=cp[0].second;
    for (int i = 1; i < n; i++)
    {
        if (cp[i-1].first == cp[i].first) {
            pc[i].second = pc[i-1].second;
        }
        else{
            pc[i].second = pc[i-1].second+1;
        }
        pc[i].first = cp[i].second;
    }

    int k = 0;
    vector<pair<pair<int,int>, int>> tmp(n);
    while ((1<<k) < n)
    {
        sort(pc.begin(), pc.end());
        for (int i = 0; i < n; i++)
        {
            tmp[i] = {{pc[i].second, pc[(i + (1<<k)) % n].second}, pc[i].first};
        }
        sort(tmp.begin(), tmp.end());

        pc[0].first = tmp[0].second;
        pc[0].second = 1;
        for (int i = 1; i < n; i++)
        {
            pc[i].first = tmp[i].second;
            if (tmp[i-1].first == tmp[i].first) {
                pc[i].second = pc[i-1].second;
            }
            else{
                pc[i].second = pc[i-1].second+1;
            }
        }
        k++;
    }
    cout<<pc[0].first;
    for (size_t i = 1; i < n; i++)
    {
        cout<< " "<< pc[i].first;
    }
    cout<<endl;

   return 0; 
}