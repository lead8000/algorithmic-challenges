#include "solution.h"

vector<int> Solution::getRow(int rowIndex) {
    vector<int> currRow(rowIndex + 1);
    currRow[0] = 1;
    int ansItem, tmp;

    for (int i = 0; i <= rowIndex; i++) {
        ansItem = 0;

        for (int j = 0; j <= i; j++) {
            tmp = currRow[j];            
            currRow[j] = ansItem + currRow[j];
            ansItem = tmp;
        }
    }

    return currRow;
}
