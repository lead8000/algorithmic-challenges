#include "solution.h"

string Solution::longestPalindrome(string s)
{
    vector<vector<bool>> dp;
    for (size_t i = 0; i < s.length(); i++) {
        vector<bool> row(s.length());
        dp.push_back(row);
    }
    pair<int,int> longestPal;
    
    for (size_t l = 0; l < s.length(); l++) {
        for (int i = 0, j = l; j < (int)s.length(); i++, j++) {
            if (s[i] == s[j] && (i+1 >= j-1 || dp[i+1][j-1])) {
                dp[i][j] = true;
                longestPal = pair<int,int>(i,j);
            }
        }
    }
    string palindrome = "";
    for (int i = longestPal.first; i <= longestPal.second; i++){
        palindrome += s[i];
    }

    return palindrome;
}