#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    /** initialize your data structure here. */
    MinStack() {
        while (!st.empty()) st.pop(); // Optional, since stack is already empty
        mini = INT_MAX;
    }

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                // Store a modified value to encode the previous minimum
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long el = st.top();
        st.pop();

        if (el < mini) {
            // Restore the previous minimum
            mini = 2LL * mini - el;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long el = st.top();
        if (el < mini) return mini; // Encoded value means real top is mini
        return el;
    }

    int getMin() {
        return st.empty() ? -1 : mini;
    }
};

