#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        for (string &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();

                int z = calc(x, y, token);
                s.push(z);
            } else {
                s.push(atoi(token.c_str()));
            }
        }
        return s.top();
    }

private:
    stack<int> s;

    int calc(int x, int y, string &op) {
        if (op == "+") return x + y;
        if (op == "-") return x - y;
        if (op == "*") return x * y;
        if (op == "/") return x / y;

        return 0;
    }

};

int main() {
    Solution s;
    vector<string> list{"2", "1", "+", "3", "*"};
    int res = s.evalRPN(list);

    cout << res;
    return 0;
}
