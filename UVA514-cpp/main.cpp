#include <iostream>
#include <stack>

using namespace std;

const int maxsize = 1000 + 5;
int n, B[maxsize];

int main() {
    while (cin >> n && n) {
        while (1) {
            int i = 1, j = 1;
            cin >> B[1];
            if (!B[1]) {
                break; // 如果第一个是 0 跳出循环
            }
            for (int i = 2; i <= n; i++) {
                cin >> B[i];// 将输入的第二行数据 存入B数组中
            }
            stack<int> s;
            while (i <= n) { // 所有的火车从A端进入的情况
                if (i == B[j]) {
                    i++;
                    j++;
                } else {
                    s.push(i++); // 将 i 入栈后 i++
                }
                while (!s.empty() && s.top() == B[j]) { // 栈不为空且栈顶等于B[j] 一直出栈
                    j++;
                    s.pop();
                }
            }
            if (j <= n) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
