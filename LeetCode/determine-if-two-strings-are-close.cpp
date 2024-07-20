class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_set<char> chars;
        map<char,int> freqChars1, freqChars2;
        
        for(auto c: word1) {
            freqChars1[c]++;
            chars.insert(c);
        }

        for(auto c: word2) {
            freqChars2[c]++;

            if (chars.find(c) == chars.end())
                return false;
        }

        map<int, int> freqs;
        for(auto c: chars) {
            freqs[freqChars1[c]]++;
        }

        for(auto c: chars) {
            if (freqs[freqChars2[c]] == 0)
                return false;
            freqs[freqChars2[c]]--;
        }

        return true;
    }
};