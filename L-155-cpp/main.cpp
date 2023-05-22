#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> preMin;

public:
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (preMin.empty()) {
            preMin.push(val);
        } else {
            preMin.push((min(preMin.top(), val)));
        }

    }

    void pop() {
        s.pop();
        preMin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return preMin.top();
    }
};

int main() {
    return 0;
}
