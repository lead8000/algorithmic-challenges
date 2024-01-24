#include <iostream>
#include "../LeetCode/solution.h"

int main() {
    Solution sol;
    auto root = new TreeNode{9, nullptr, nullptr};
    cout<<sol.pseudoPalindromicPaths(root)<<endl;
    return 0;
}
