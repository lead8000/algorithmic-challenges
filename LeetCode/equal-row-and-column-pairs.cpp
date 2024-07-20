class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<string,int> freqs;
        for(auto row: grid) {
            string rowStr = "";
            for(auto x: row) {
                rowStr += to_string(x) + ",";
            }
            freqs[rowStr]++;
        }

        int result = 0;
        for(int c = 0; c<n; c++) {
            string rowStr = "";
            for(int r=0; r<n; r++) {
                rowStr += to_string(grid[r][c]) + ",";
            }
            result += freqs[rowStr];
        }

        return result;
    }
};