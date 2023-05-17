#include <iostream>
#include <stack>

using namespace std;

const int maxsize = 26 + 5;

struct Matrix {
    int a, b;

    Matrix(int a = 0, int b = 0) : a(a), b(b) {}
} m[maxsize];

stack<Matrix> s;

int main() {

    int n;
    char c;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        int k = c - 'A'; // 转化为整数 ASCII码相减
        cin >> m[k].a >> m[k].b; // 输入矩阵的行列
    }
    while (cin >> str) {
        int len = str.length();
        bool error = false; // 是否出错
        int ans = 0; // 记录乘法次数
        for (int i = 0; i < len; i++) {
            if (isalpha(str[i])) // 如果是字母 对于下标立即入栈
            {
                s.push(m[str[i] - 'A']); // m是存储节点的数组
            } else if (str[i] == ')') {
                Matrix m2 = s.top(); // 弹栈：先取栈顶 再pop
                s.pop();

                Matrix m1 = s.top();
                s.pop();

                if (m1.b != m2.a) { // m1的列值 = m2的行值为ture 可进行下一步运算
                    error = true;
                    break;
                }

                ans += m1.a * m1.b * m2.b; // m1的行 * m1的列 * m2的行
                s.push(Matrix(m1.a, m2.b)); // 结果矩阵入栈
            }
        }
        if (error) {
            cout << "error" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
