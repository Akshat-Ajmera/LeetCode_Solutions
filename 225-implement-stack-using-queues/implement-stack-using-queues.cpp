class MyStack {
private:
    int ptr;
    vector<int> stack;
public:
    MyStack() {
        stack.resize(100);
        ptr = 0;
    }
    void push(int x) {
        stack[ptr] = x;
        ptr++;
        return;
    }
    int pop() {
        ptr--;
        return stack[ptr];
    }
    int top() {
        return stack[ptr-1];
    }
    bool empty() {
        return !ptr;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */