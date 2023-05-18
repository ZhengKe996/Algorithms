#include <iostream>
#include <string>

/**
 * 题意：7 3 1 6 1 6 4 3 1 6 1 6 1 3 7 （第一个数是 N ,其余各位表示交替表示0和1 的个数）
 */
using namespace std;
string s1, s; // 定义两个字符串类型 需要引入 string 头文件

int main() {
    int n, count = 1;
    cin >> s;
    n = s.size(); // n存储 s的长度
    cout << n; // 输出第一位 N
    for (int i = 0; i < n - 1; i++) {
        cin >> s1;// 输入余下的 n-1行
        s = s + s1;
    }
    if (s[0] == '1') {
        cout << " " << 0; // 注意输出格式 AC时可能会不通过
    }
    for (int i = 0; i < n * n; i++) {
        if (s[i] == s[i + 1]) {
            count++; // 连续的0或1 就++
        } else {
            cout << " " << count; // 反之输出 count并复位
            count = 1;
        }
    }
    cout << endl;
    return 0;
}
