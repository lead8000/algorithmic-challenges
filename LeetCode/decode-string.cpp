class Solution {
public:
    string decodeString(string s) {
        deque<char> dq;

        for(char c: s) {
            if (c == ']') {
                // extract the string to replicate and store it in a stack
                deque<char> tmp;
                while (dq.back() != '[') {
                    tmp.push_front(dq.back());
                    dq.pop_back();
                }
                dq.pop_back(); // remove '['

                // get the K number of repetition
                string number = "";
                while (!dq.empty() && 0 <= dq.back() - '0' && dq.back() - '0' <= 9) {
                    number = dq.back() + number;
                    dq.pop_back();
                }
                int k = stoi(number);

                // decode this chuck of the string
                for (int i = 0; i<k; i++) {
                    for(char c: tmp) {
                        dq.push_back(c);
                    }
                }
            }
            else {
                dq.push_back(c);
            }
        }

        return string(dq.begin(), dq.end());
    }
};