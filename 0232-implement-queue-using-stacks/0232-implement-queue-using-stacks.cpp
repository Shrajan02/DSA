// Design using 2 stacks
// pop operation expensive
class MyQueue {
private:
    int n;
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        n = 0;
    }
    
    void push(int x) {
        s1.push(x);
        n++;
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int poppedVal = s2.top();
        s2.pop();
        n--;
        return poppedVal;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }
    
    bool empty() {
        return (n == 0);
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