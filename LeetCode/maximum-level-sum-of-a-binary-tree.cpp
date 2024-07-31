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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maxSum = root->val, maxLevel = 1, currLevelSum = 0, currLevel = 1;

        queue<pair<int, TreeNode*>> q;
        q.push({1,root});
        
        while(!q.empty()) {
            auto node = q.front();
            
            if (currLevel < node.first) {
                if (currLevelSum > maxSum) {
                    maxSum = currLevelSum;
                    maxLevel = currLevel;
                }
                currLevelSum = 0;
                currLevel++;
            }

            currLevelSum += node.second->val;
            
            if (node.second->left != nullptr) {
                q.push({node.first+1, node.second->left});
            }
            if (node.second->right != nullptr) {
                q.push({node.first+1, node.second->right});
            }
            q.pop();
        }
        if (currLevelSum > maxSum) {
            maxSum = currLevelSum;
            maxLevel = currLevel;
        }

        return maxLevel;
    }
};