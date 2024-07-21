class RecentCounter {
private: 
    deque<int> dq;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!dq.empty() && t-dq.front() > 3000) {
            dq.pop_front();
        }
        dq.push_back(t);

        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */