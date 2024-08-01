class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> visitedCell(maze.size(), vector<bool>(maze[0].size()));

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{entrance[0],entrance[1]}});
        visitedCell[entrance[0]][entrance[1]] = true;

        int vX[4] = { 0, 1, 0,-1};
        int vY[4] = {-1, 0, 1, 0};

        auto isValidCell = [maze](int row, int col) -> bool {
            return row >= 0 && col >= 0 && row <= maze.size()-1 && col <= maze[0].size()-1;
        };
        auto isEdgeCell = [maze](int row, int col) -> bool {
            return row == 0 || col == 0 || row == maze.size()-1 || col == maze[0].size()-1;
        };

        while(!q.empty()) {
            auto cell = q.front();
            int distance = cell.first, row = cell.second.first, col = cell.second.second;

            if (isEdgeCell(row, col) && !(row == entrance[0] && col == entrance[1]))
                return distance;

            for(int d = 0; d < 4; d++) {
                if (isValidCell(row + vY[d], col + vX[d]) && maze[row + vY[d]][col + vX[d]] == '.' && !visitedCell[row + vY[d]][col + vX[d]]) {
                    visitedCell[row + vY[d]][col + vX[d]] = true;
                    q.push({distance+1, {row + vY[d], col + vX[d]}});
                }
            }

            q.pop();
        }

        return -1;
    }
};