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
class Solution {
private: 
    int visitDfs(TreeNode* root, int maxVal) {
        if (!root) {
            return 0;
        }
        return (root->val >= maxVal) + visitDfs(root->left, max(root->val, maxVal)) + visitDfs(root->right, max(root->val, maxVal));
    }
public:
    int goodNodes(TreeNode* root) {
        return visitDfs(root, root->val);
    }
};