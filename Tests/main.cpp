#include <iostream>
#include "../LeetCode/solution.h"

int main() {
    Solution sol;

    auto result = sol.generate(5);

    for (auto &&row : result){
        for (auto &&i : row)
            cout<<i<<" ";
        cout<<endl;
    } 

    return 0;
}
