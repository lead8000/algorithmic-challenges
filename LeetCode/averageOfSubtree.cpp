#include "solution.h"

int Solution::averageOfSubtree(TreeNode* root) {
    return dfs(root).first;
}

pair<int,pair<int,int>> dfs(TreeNode* root) {
    if (root == nullptr) {
        return pair<int,pair<int,int>>(0, pair<int,int>(0,0));
    }

    if (root->left == nullptr && root->right == nullptr) {
        return pair<int,pair<int,int>>(1, pair<int,int>(1,root->val));
    }

    auto leftSubtree = dfs(root->left);
    auto rightSubtree = dfs(root->right);

    int subtreeSum = leftSubtree.second.second + rightSubtree.second.second + root->val;
    int amountNodes = leftSubtree.second.first + rightSubtree.second.first + 1;

    if ((int)floor((float)subtreeSum / amountNodes) == root->val) {
        return pair<int,pair<int,int>>(
            leftSubtree.first + rightSubtree.first + 1, 
            pair<int,int>(amountNodes, subtreeSum)
        );
    }

    return pair<int,pair<int,int>>(
        leftSubtree.first + rightSubtree.first, 
        pair<int,int>(amountNodes, subtreeSum)
    );
}