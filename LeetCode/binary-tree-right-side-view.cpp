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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sideView;
        
        if (!root) return sideView;

        queue<pair<int, TreeNode*>> q;
        q.push({1, root});

        int height = 1;
        while(!q.empty()) {
            auto node = q.front();
            if (node.first == height) {
                sideView.push_back(node.second->val);
                height++;
            }
            if (node.second->right != nullptr)
                q.push({node.first+1, node.second->right});
            if (node.second->left != nullptr)
                q.push({node.first+1, node.second->left});
            q.pop();
        }

        return sideView;
    }
};