class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int timestamp = customers[0][0];
        int totalOfWaiting = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (timestamp >= customers[i][0]) {
                timestamp += customers[i][1];
                totalOfWaiting += (timestamp - customers[i][0]);
            }
            else {
                timestamp = customers[i][0];
                totalOfWaiting += customers[i][1];
            }
        }

        return (double)totalOfWaiting / (double)customers.size();
    }
};