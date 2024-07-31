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
    int visitDfs(TreeNode* root, vector<int> &leafSeq) {
        if (!root)
            return 0;

        int dephLeft  = visitDfs(root->left, leafSeq);
        int dephRight = visitDfs(root->right, leafSeq);
        if (dephLeft == 0 && dephRight == 0) {
            leafSeq.push_back(root->val);
        }

        return max(dephLeft, dephRight) + 1;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSeq1, leafSeq2;

        visitDfs(root1, leafSeq1);
        visitDfs(root2, leafSeq2);

        return leafSeq1 == leafSeq2;
    }
};