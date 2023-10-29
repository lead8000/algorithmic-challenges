#include <iostream>
#include "../LeetCode/solution.h"

int main() {
    Solution sol;

    auto result = sol.poorPigs(1000, 15, 60);

    cout<<"answer: "<<result<<endl;
    // for (auto &&row : result){
    //     for (auto &&i : row)
    //         cout<<i<<" ";
    //     cout<<endl;
    // } 

    return 0;
}
