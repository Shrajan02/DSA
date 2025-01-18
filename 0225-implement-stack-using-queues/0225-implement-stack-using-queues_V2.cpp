// Design using 2 queues
// push operation expensive 
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
        q2.push(x);
        n++;
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int poppedVal = q1.front();
        q1.pop();
        n--;
        return poppedVal;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return (n == 0);
    }
};
