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
    int visitDfs(TreeNode* root, map<long long,int> &path, long long currSum, int targetSum) {
        if (!root) return 0;
        
        currSum += (long long)root->val;
        path[currSum]++;

        int leftPaths  = visitDfs(root->left, path, currSum, targetSum);
        int rightPaths = visitDfs(root->right, path, currSum, targetSum);
        
        path[currSum]--;

        int tmpResult = path[currSum-targetSum] + leftPaths + rightPaths;

        if (currSum==(long long)targetSum) tmpResult++;

        return tmpResult;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        map<long long,int> path;
        return visitDfs(root, path, 0, targetSum);
    }
};