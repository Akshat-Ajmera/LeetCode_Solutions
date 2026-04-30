struct LLNode {
    int val;
    LLNode* prev;
    LLNode* next;

    LLNode(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class FrontMiddleBackQueue {
private:
    int cnt = 0;
    LLNode* front = NULL;
    LLNode* middle = NULL;
    LLNode* back = NULL;
public:
    FrontMiddleBackQueue() {}
    void pushFront(int val) {
        LLNode* node = new LLNode(val);
        node -> next = front;
        if(front) front -> prev = node;
        front = node;
        if(!cnt) {
            back = front;
            middle = front;
        }
        else if(cnt % 2) middle = middle -> prev;
        cnt++;
        return;
    }
    void pushMiddle(int val) {
        LLNode* node = new LLNode(val);
        if(!cnt) {
            front = back = middle = node;
            cnt++;
            return;
        }
        if(cnt == 1) {
            node -> next = front;
            front -> prev = node;
            front = node;
            middle = node;
            cnt++;
            return;
        }
        if(!(cnt % 2)) middle = middle -> next;
        LLNode* prevNode = middle -> prev;
        if(prevNode) prevNode -> next = node;
        node -> prev = prevNode;
        node -> next = middle;
        middle -> prev = node;
        if(middle == front) front = node;
        middle = node;
        cnt++;
        return;
    }
    void pushBack(int val) {
        LLNode* node = new LLNode(val);
        node -> prev = back;
        if(back) back -> next = node;
        back = node;
        if(!cnt) {
            front = back;
            middle = back;
        }
        else if(!(cnt % 2)) middle = middle -> next;
        cnt++;
        return;
    }
    int popFront() {
        if(!cnt) return -1;
        int data = front -> val;
        if(cnt == 1) {
            front = back = middle = NULL;
            cnt--;
            return data;
        }
        front = front -> next;
        if(front) front -> prev = NULL;
        if(!(cnt % 2)) middle = middle -> next;
        cnt--;
        return data;
    }
    int popMiddle() {
        if(!cnt) return -1;
        int data = middle -> val;
        if(cnt == 1) {
            front = back = middle = NULL;
            cnt--;
            return data;
        }
        LLNode* prevNode = middle -> prev;
        LLNode* nextNode = middle -> next;
        if(prevNode) prevNode -> next = nextNode;
        if(nextNode) nextNode -> prev = prevNode;
        if(middle == front) front = nextNode;
        if(middle == back) back = prevNode;
        if(cnt % 2) middle = prevNode;
        else middle = nextNode;
        cnt--;
        return data;
    }
    int popBack() {
        if(!cnt) return -1;
        int data = back -> val;
        if(cnt == 1) {
            front = back = middle = NULL;
            cnt--;
            return data;
        }
        back = back -> prev;
        if(back) back -> next = NULL;
        if(cnt % 2) middle = middle -> prev;
        cnt--;
        return data;
    }
};