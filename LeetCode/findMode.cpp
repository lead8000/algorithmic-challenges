#include "solution.h"

vector<int> findMode(TreeNode* root) {
    unordered_map<int,int> freq;
    int mode;

    dfs(root, freq, &mode);

    vector<int> modes;
    for (auto &&kv : freq){ 
        if (kv.second == mode) {
            modes.push_back(kv.first);
        } 
    } 

    return modes;
}

void dfs(TreeNode* root, unordered_map<int,int>& freq, int* mode)
{
    freq[root->val]++;
    
    if (freq[root->val] > *mode)
        *mode = freq[root->val];
 
    if (root->left != nullptr)
        dfs(root->left, freq, mode);

    if (root->right != nullptr)
        dfs(root->right, freq, mode);
}