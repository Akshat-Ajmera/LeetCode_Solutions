class MedianFinder {
private:
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
public:
    MedianFinder() {}
    void addNum(int num) {
        if(maxPQ.empty() && minPQ.empty()) {
            maxPQ.push(num);
            return;
        }
        if(maxPQ.size() == minPQ.size()) {
            if(num < minPQ.top()) {
                maxPQ.push(num);
            }
            else {
                maxPQ.push(minPQ.top());
                minPQ.pop();
                minPQ.push(num);
            }
        }
        else {
            if(num > maxPQ.top()) {
                minPQ.push(num);
            }
            else {
                minPQ.push(maxPQ.top());
                maxPQ.pop();
                maxPQ.push(num);
            }
        }
        return;
    }
    double findMedian() {
        if(maxPQ.size() == minPQ.size()) return (((double) maxPQ.top() + (double) minPQ.top()) / 2.0);
        else return (double) maxPQ.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */