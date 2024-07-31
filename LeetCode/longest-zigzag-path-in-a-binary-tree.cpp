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
    int visitDfs(TreeNode* root, int currLength, char lastTurn) {
        if (!root) return 0;

        int longestLeftPath = 1, longestRightPath = 1;

        if (lastTurn == 'L') {
            longestRightPath += currLength;
        }
        else if (lastTurn == 'R') {
            longestLeftPath += currLength;
        }
        
        longestLeftPath  = visitDfs(root->left, longestLeftPath, 'L');
        longestRightPath = visitDfs(root->right, longestRightPath, 'R');

        return max(currLength, max(longestLeftPath, longestRightPath));
    }
public:
    int longestZigZag(TreeNode* root) {
        return visitDfs(root, 0, ' ');
    }
};