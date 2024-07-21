class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> qp, qn;

        for(int size: asteroids) {
            if (size > 0) {
                qp.push_back(size);
            }
            else {
                while(!qp.empty() && abs(size) > qp.back()) {
                    qp.pop_back();
                }
                if (qp.empty())
                    qn.push_back(size);
                else if (abs(size) == qp.back())
                    qp.pop_back();
            }
        }

        vector<int> result(qn.begin(), qn.end());
        result.insert(result.end(), qp.begin(), qp.end());

        return result;
    }
};