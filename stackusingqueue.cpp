#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;  // Make q a member variable

public:
    MyStack() {
        // No need to define q here again
    }

    void push(int x) {
        int s = q.size();
        q.push(x);
        // Rotate the queue to bring new element to the front
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
