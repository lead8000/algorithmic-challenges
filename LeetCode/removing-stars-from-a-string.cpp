class Solution {
public:
    string removeStars(string s) {
        deque<char> q;
        
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                q.pop_back();
            }
            else {
                q.push_back(s[i]);
            }
        }

        return string(q.begin(), q.end());
    }
};