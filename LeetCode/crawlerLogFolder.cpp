#include <cstring>
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int height = 0;
        const char* goBack = "../";
        const char* nothing = "./";

        for (int i = 0; i < logs.size(); i++) {
            if (logs[i].compare(goBack) == 0) {
                height--;
            }
            else if (logs[i].compare(nothing) != 0) {
                height++;
            }
        }

        return height;
    }
};