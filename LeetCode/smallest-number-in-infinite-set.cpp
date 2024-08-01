class SmallestInfiniteSet {
private:
    priority_queue<int> heap;
    int smallestValue;
public:
    SmallestInfiniteSet() {
        smallestValue = 1;
    }

    int popSmallest() {
        if (heap.empty() || smallestValue < -heap.top())
            return smallestValue++;
        int tmp = -heap.top();
        while (!heap.empty() && tmp == -heap.top()) {
            heap.pop();
        }
        return tmp;
    }

    void addBack(int num) {
        if (num < smallestValue)
            heap.push(-num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */