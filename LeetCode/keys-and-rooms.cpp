class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        int amountVisitedRooms = 0;

        queue<int> q;
        visited[0] = true;
        amountVisitedRooms++;
        q.push(0);

        while(!q.empty()) {
            int room = q.front();

            for (auto key: rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    amountVisitedRooms++;
                    q.push(key);
                }
            }

            q.pop();
        }

        return amountVisitedRooms == rooms.size();
    }
};