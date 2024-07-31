class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int amountCC = 0;
        
        for(int i = 0; i < isConnected.size(); i++) {
            if (visited[i]) continue;
            amountCC++;

            queue<int> q;
            
            for(int j = i+1; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1) {
                    visited[i] = true;
                    q.push(j);
                }
            }

            while (!q.empty()) {
                int node = q.front();
                visited[node] = true;

                for (int j = i+1; j < isConnected.size(); j++) {
                    if (node != j && isConnected[node][j] == 1 && !visited[j]) {
                        q.push(j);
                    }
                }
                q.pop();
            }
        }

        return amountCC;
    }
};