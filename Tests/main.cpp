#include <iostream>
#include "../LeetCode/solution.h"

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 2, 7};  // Puedes cambiar esto por los valores que desees
    int result = sol.minOperations(nums);
    cout << "Resultado: " << result << endl;
    return 0;
}
