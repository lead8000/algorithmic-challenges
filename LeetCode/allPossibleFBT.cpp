#include "solution.h"

vector<TreeNode*> Solution::allPossibleFBT(int n) {
    if (n % 2 == 0)
        return vector<TreeNode*>();

    vector<vector<TreeNode*>> dp;

    auto firstTree = vector<TreeNode*>();
    TreeNode *root = new TreeNode(0);
    firstTree.push_back(root);
    dp.push_back(firstTree);

    for (int i = 3; i <= n; i+=2) {
        vector<TreeNode*> trees;

        for (int j = 1; j < i; j+=2) {
            auto treesOfSizeJ   = dp[(j-1)/2];
            auto treesOfSizeI_J = dp[(i-j-1)/2];

            for (auto treeJ: treesOfSizeJ) {
                for (auto treeI_J: treesOfSizeI_J) {
                    TreeNode* root = new TreeNode(0, treeJ, treeI_J);
                    trees.push_back(root);
                }
            }
        }
        dp.push_back(trees);
    }

    return dp[(n-1)/2];    
}