#include <iostream>
#include "../LeetCode/solution.h"

int main() {
    Solution sol;

    vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
    vector<int> people = {2,3,7,11};
    auto result = sol.fullBloomFlowers(flowers, people);

    for (auto &&i : result) 
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
