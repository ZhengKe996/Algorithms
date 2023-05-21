#include <iostream>

using namespace std;

int main() {
    int cnt = 0; // 局部变量一定要初始化
    string s;
    getline(cin, s); // 读取一行
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            cnt++; // 统计所有非空格字符
        }
    }
    cout << cnt;
    return 0;
}
