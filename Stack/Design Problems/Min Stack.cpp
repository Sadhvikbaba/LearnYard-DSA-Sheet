class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        } else {
            minSt.push(minSt.top());
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }

    int top() {
        if (st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }
};
