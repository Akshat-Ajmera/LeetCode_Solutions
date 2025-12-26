class MyQueue {
private:
    int ptr0, ptr1;
    vector<int> queue;
public:
    MyQueue() {
        queue.resize(100);
        ptr0 = 0, ptr1 = 0;
    }
    void push(int x) {
        queue[ptr1] = x;
        ptr1++;
        return;
    }
    int pop() {
        ptr0++;
        return queue[ptr0-1];
    }
    int peek() {
        return queue[ptr0];
    }
    bool empty() {
        return( ptr0 == ptr1);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */