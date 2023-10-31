#include "solution.h"

vector<int> Solution::findArray(vector<int>& pref) {
    int prefiXor = pref[0];

    for (int i = 1, nextItem; i < (int)pref.size(); i++) {
        nextItem = prefiXor ^ pref[i];
        prefiXor = pref[i];
        pref[i] = nextItem;
    }

    return pref;
}