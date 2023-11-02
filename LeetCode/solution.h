#include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums);
    int minOperations(vector<int>& nums);
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people);
    vector<vector<int>> generate(int numRows);
    int kthGrammar(int n, int k);
    string longestPalindrome(string s);
    vector<int> getRow(int rowIndex);
    int maxProfit(vector<int>& prices);
    int poorPigs(int buckets, int minutesToDie, int minutesToTest);
    vector<int> sortByBits(vector<int>& arr);
    int climbStairs(int n);
    vector<int> findArray(vector<int>& pref);
    int getMaximumGenerated(int n);
    vector<int> findMode(TreeNode* root);
    bool isSubsequence(string s, string t);
    int averageOfSubtree(TreeNode* root);
    vector<TreeNode*> allPossibleFBT(int n);
};
