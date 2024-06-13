#include "solution.h";

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int amountMoves = 0;
        for (int i = 0; i < seats.size(); i++) {
            amountMoves += abs(seats[i] - students[i]);
        }
        return amountMoves;
    }
};