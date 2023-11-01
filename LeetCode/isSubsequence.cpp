#include "solution.h"

bool isSubsequence(string s, string t) {

    if (s.length() == 0)
        return true;

    for (int i = 0, j = 0; i < t.length() && j < s.length(); i++)
    {
        if (s[j] == t[i]) {
            j++;
            if (j == s.length())
                return true;
        }
    }

    return false;
}
