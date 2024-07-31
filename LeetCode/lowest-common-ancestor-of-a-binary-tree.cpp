/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (root == p || root == q) {
            return root;
        }
        else {
            TreeNode* findP = lowestCommonAncestor(root->left, p, q);
            TreeNode* findQ = lowestCommonAncestor(root->right, p, q);  

            if (findP != nullptr && findQ != nullptr) {
                return root;
            }
            if (findP != nullptr) return findP;            
            return findQ;
        }
    }
};