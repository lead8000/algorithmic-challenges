namespace LeetCode;

public partial class Solution {
    public int KthGrammar(int n, int k) {
        if (n == 1 && k == 1)
            return 0;

        int kth = (int)System.Math.Ceiling((double)k/2);

        if (k % 2 == 1)
            return KthGrammar(n-1, kth) == 0 ? 0 : 1;
        return KthGrammar(n-1, kth) == 0 ? 1 : 0;
    }

    // // n=30 k=434991989
    // // Memory Limit Exceded
    // public int KthGrammar(int n, int k) {
    //     int[] last_row = new int[(1<<(n-1))];
    //     int[] curr_row = new int[(1<<(n-1))];
    //     curr_row[0] = 0;

    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < (1<<i); j++) {
    //             last_row[j] = curr_row[j];
    //         }

    //         for (int j = 0, h = 0; h < (1<<i); j++) {
    //             curr_row[h++] = last_row[j] == 0 ? 0 : 1;
    //             curr_row[h++] = last_row[j] == 0 ? 1 : 0;
    //         }
    //     }

    //     return curr_row[k-1];   
    // }
}