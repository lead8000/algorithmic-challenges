#include "solution.h"

template <typename Iterator>
bool compressChars(vector<char>& chars, Iterator currChar, Iterator it) {
    if (currChar+1 == it){
        *it = '2';
        return false;
    }
    else if (*(it-1) != '9') {
        *(it-1)=(char)(*(it-1)+1);
        chars.erase(it); 
        return true;
    }
    else {
        for (auto iit = it-1; currChar != iit; iit--) {
            if (*iit == '9') {
                *iit = '0';
            }
            else {
                *iit=(char)(*iit+1);
                chars.erase(it);
                return true;
            }
        }
        chars.insert(currChar+1, '1');
        chars.erase(it+1);
        return false;
    }
}

int Solution::compress(vector<char>& chars) {
    auto currCharIt = chars.begin();

    for (auto it=chars.begin()+1; it != chars.end();) {
        if (*currCharIt == *it) {
            if (!compressChars(chars, currCharIt, it)) {
                it++;
            }
        }
        else {
            currCharIt = it;
            it++;
        }
    }

    return chars.size();
}
