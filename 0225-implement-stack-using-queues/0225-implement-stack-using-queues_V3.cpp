// Design using 2 queues
// pop operation expensive 
class MyStack {
private:
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        n = 0;
    }
    
    void push(int x) {
        q1.push(x);
        n++;
    }
    
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int poppedVal = q1.front();
        q1.pop();
        n--;
        swap(q1, q2);
        return poppedVal;
    }
    
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topVal = q1.front();
        q1.pop();
        q2.push(topVal);
        swap(q1, q2);
        return topVal;
    }
    
    bool empty() {
        return (n == 0);
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
