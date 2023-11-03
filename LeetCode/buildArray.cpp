#include "solution.h"

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> opers;
    int ptr = 0;

    for (int i = 1; i <= n; i++) {
        if (target[ptr] == i) {
            opers.push_back("Push");
            ptr++;
        }
        else {
            opers.push_back("Push");
            opers.push_back("Pop");
        }
        if (ptr == (int)target.size()) 
            break;
    }

    return opers;
}