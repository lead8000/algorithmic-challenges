class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int amountFreshOranges = 0;
        queue<pair<int,pair<int,int>>> q;

        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    amountFreshOranges++;
                }
                else if (grid[i][j] == 2) {
                    q.push({0,{i,j}});
                }
            }
        }

        int vR[] = {-1, 0, 1, 0};
        int vC[] = { 0, 1, 0,-1};

        auto isValidCell = [grid](int row, int col) -> bool  {
            return 0 <= row && row < grid.size() && 0 <= col && col < grid[0].size();
        };

        int minSteps = 0;

        while (!q.empty()) {
            auto rotteOrangeCell = q.front();
            minSteps = rotteOrangeCell.first;

            for (int d = 0; d < 4; d++) {
                int row = rotteOrangeCell.second.first + vR[d];
                int col = rotteOrangeCell.second.second + vC[d];
                
                if (isValidCell(row, col) && grid[row][col] == 1) {
                    grid[row][col] = 2;
                    q.push({rotteOrangeCell.first+1, {row,col}});
                    amountFreshOranges--;
                }
            }
            q.pop();
        }

        return amountFreshOranges == 0 ? minSteps : -1;
    }
};