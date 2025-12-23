class MyCircularQueue {
private:
    int k, begin, end, cnt;
    vector<int> circularQueue;
public:
    MyCircularQueue(int K) {
        k = K, begin = 0, end = 0, cnt = 0;
        circularQueue.resize(k);
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        circularQueue[end] = value;
        cnt++;
        end = (end + 1) % k;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;
        cnt--;
        begin = (begin + 1) % k;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : circularQueue[begin];
    }
    
    int Rear() {
        return isEmpty() ? -1 : circularQueue[(end - 1 + k) % k];
    }
    
    bool isEmpty() {
        return !cnt;
    }
    
    bool isFull() {
        return cnt == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */