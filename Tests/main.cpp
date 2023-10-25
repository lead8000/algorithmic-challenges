#include <iostream>
#include "../LeetCode/solution.h"

int main() {
    Solution sol;

    auto result = sol.kthGrammar(2, 2);

    cout<<"answer: "<<result<<endl;
    // for (auto &&row : result){
    //     for (auto &&i : row)
    //         cout<<i<<" ";
    //     cout<<endl;
    // } 

    return 0;
}
