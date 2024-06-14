#include <bits/stdc++.h>

#define print_arr(arr) for (size_t i = 0; i < arr.size(); i++) {if (i+1 != arr.size()) { cout<<arr[i]<<" "; } else { cout<<arr[i]<<endl; } }


using namespace std;

class SuffixArray {
private:
    string __s;
    vector<int> __p;

    void RadixSort(vector<pair<pair<int,int>,int>> &a) {
        int n = a.size();

        vector<vector<pair<pair<int,int>,int>>> second_order(n);
        for (size_t i = 0; i < n; i++) {
            second_order[a[i].first.second].push_back(a[i]);
        }

        vector<vector<pair<pair<int,int>,int>>> first_order(n);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < second_order[i].size(); j++)
            {
                first_order[second_order[i][j].first.first].push_back(second_order[i][j]);
            }
        }
        int iia = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < first_order[i].size(); j++)
            {
                a[iia++] = first_order[i][j];
            }
        }
    }

    void Build(string s) {
        int n = s.size();

        vector<int> c(n);
        {
            // k = 0
            vector<pair<char, int>> a(n);
            for (size_t i = 0; i < n; i++) a[i] = {s[i], (int)i};
            sort(a.begin(), a.end());

            c[a[0].second] = 0;
            for (size_t i = 1; i < n; i++) {
                if (a[i-1].first == a[i].first) {
                    c[a[i].second] = c[a[i-1].second];
                }
                else {
                    c[a[i].second] = c[a[i-1].second] + 1;
                }
            }
        }

        int k = 0;
        vector<pair<pair<int,int>,int>> a(n);
        while ((1<<k) < n)
        {
            for (size_t i = 0; i < n; i++) {
                a[i] = {{c[(i - (1<<k)+n) % n], c[i]}, (int)i};
            }
            RadixSort(a);

            c[a[0].second] = 0;
            for (size_t i = 1; i < n; i++) {
                if (a[i-1].first == a[i].first) {
                    c[a[i].second] = c[a[i-1].second];
                }
                else{
                    c[a[i].second] = c[a[i-1].second]+1;
                }
            }
            k++;
        }

        for (size_t i = 0; i < n; i++) __p.push_back(a[i].second);
    }

public:
    SuffixArray(string s) {
        Build(s);
    }

    int getIndex(int i) const {
        return __p[i];
    }
};

int main(){
    string s = "ababba$";

    auto suff = SuffixArray(s);
    int p;

    for (size_t i = 0; i < s.size(); i++)
    {
        p = suff.getIndex(i);
        cout<<p<<"--"<<s.substr(p, s.size()-p)<<endl;
    }

   return 0; 
}