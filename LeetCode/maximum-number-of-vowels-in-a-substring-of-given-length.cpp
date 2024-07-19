#include "solution.h"

inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

int Solution::maxVowels(string s, int k) {
    int currAmount = 0;
    for (int i=0; i<k; i++) {
        if (isVowel(s[i]))
            currAmount++;
        if (currAmount == k) break;
    }

    int maxAmount = currAmount;
    for (int i=k; i<s.size(); i++) {
        if (isVowel(s[i]))
            currAmount++;
        if (isVowel(s[i-k]))
            currAmount--;
        maxAmount = max(maxAmount, currAmount);

        if (currAmount == k) break;
    }

    return maxAmount;
}