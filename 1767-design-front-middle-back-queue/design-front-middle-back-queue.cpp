class FrontMiddleBackQueue {
private:
    deque<int> front, back;
    int sizeDiff() { return (front.size() - back.size()); }
public:
    FrontMiddleBackQueue() {}
    void pushFront(int val) {
        if(sizeDiff()) {
            int last = front.back();
            back.push_front(last);
            front.pop_back();
        }
        front.push_front(val);
        return;
    }
    void pushMiddle(int val) {
        if(sizeDiff()) {
            int last = front.back();
            back.push_front(last);
            front.pop_back();
        }
        front.push_back(val);
        return;
    }
    void pushBack(int val) {
        if(!sizeDiff()) {
            if(back.empty()) {
                pushFront(val);
                return;
            }
            int first = back.front();
            front.push_back(first);
            back.pop_front();
        }
        back.push_back(val);
        return;
    }
    int popFront() {
        if(front.empty()) return -1;
        if(!sizeDiff()) {
            int first = back.front();
            front.push_back(first);
            back.pop_front();
        }
        int val = front.front();
        front.pop_front();
        return val;
    }
    int popMiddle() {
        if(front.empty()) return -1;
        int val = front.back();
        front.pop_back();
        if(sizeDiff()) {
            int first = back.front();
            front.push_back(first);
            back.pop_front();
        }
        return val;
    }
    int popBack() {
        if(back.empty()) return popMiddle();
        if(sizeDiff()) {
            int last = front.back();
            back.push_front(last);
            front.pop_back();
        }
        int val = back.back();
        back.pop_back();
        return val;
    }
};