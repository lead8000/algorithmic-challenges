class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;

        for(int i = 0; i < t.size(); i++) {
            if (s[ptr] == t[i]) 
                ptr++;
            if (ptr == s.size()) 
                return true; // s is a subsequence of t
        }

        return ptr == s.size();
    }
};