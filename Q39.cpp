class MinStack {
public:
    stack<int> s;
    stack<int> min_s;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        min_s.push(min_s.empty() ? x : min(x, min_s.top()));
    }

    void pop() {
        s.pop();
        min_s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};
