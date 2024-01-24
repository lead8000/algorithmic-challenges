#include "solution.h"

void dfs_visit(TreeNode* current, int oddAmount, int freq[], int& result) {

    freq[current->val] += 1;
    if (freq[current->val] % 2 == 1) {
        oddAmount++;
    }
    else {
        oddAmount--;
    }

    if (current->left == nullptr && current->right == nullptr && (oddAmount == 0 || oddAmount == 1)) {
        result++;
    }
    if (current->left != nullptr) {
        dfs_visit(current->left, oddAmount, freq, result);
    }
    if (current->right != nullptr) {
        dfs_visit(current->right, oddAmount, freq, result);
    }

    freq[current->val] -= 1;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int Solution::pseudoPalindromicPaths(TreeNode* root) {

    int result = 0;
    int dict[] = {0,0,0,0,0,0,0,0,0,0};

    dfs_visit(root, 0, dict, result);

    return result;
}
