class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> mask(n, false);

        int ii = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; ii++) {
                if (!mask[ii % n]) {
                    j++;
                }
            }
            ii--;
            mask[ii % n] = true;
        }

        return (ii % n) + 1;
    }
};