class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dqR, dqD;
        for (int i = 0; i<senate.size(); i++) {
            if (senate[i] == 'R') {
                dqR.push(i);
            }
            else {
                dqD.push(i);
            }
        }

        while (!dqR.empty() && !dqD.empty()) {
            if (dqR.front() < dqD.front()) {
                dqD.pop();
                dqR.push(dqR.front()+senate.size());
                dqR.pop();
            }
            else {
                dqR.pop();
                dqD.push(dqD.front()+senate.size());
                dqD.pop();
            }
        }

        if (dqR.empty())
            return "Dire";
        return "Radiant";
    }
};