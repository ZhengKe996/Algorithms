#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {""};
        }
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            // 加法原理
            vector<string> A = generateParenthesis(i - 1);
            vector<string> B = generateParenthesis(n - i);

            // 乘法原理
            for (string &a: A) {
                for (string &b: B) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        return ans;

    }

    // 优化后
    vector<string> generateParenthesis2(int n) {
        if (n == 0) {
            return {""};
        }
        if (store.find(n) != store.end()) {
            return store[n];// 记忆化
        }
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            // 加法原理
            vector<string> A = generateParenthesis(i - 1);
            vector<string> B = generateParenthesis(n - i);

            // 乘法原理
            for (string &a: A) {
                for (string &b: B) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        store[n] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<string>> store;
};

int main() {
    return 0;
}
