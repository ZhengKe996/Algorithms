#include <list>
#include <string>
#include <iostream>

using namespace std;


/**
 * 使用链表
 * @param s
 */
void solve(string s) {
    int len = s.length();
    list<char> text;
    list<char>::iterator it = text.begin(); // 初始化迭代器指向行首
    for (int i = 0; i < len; i++) {
        if (s[i] == '[') {
            it = text.begin(); // 往前插返回指针
        } else if (s[i] == ']') {
            it = text.end(); // 往后插返回指针
        } else {
            it = text.insert(it, s[i]);
            it++;
        }
    }
    for (it = text.begin(); it != text.end(); it++) {
        cout << *it; // 使用迭代器输出 it++ 代表指针往后移动
    }
    s.clear();
    cout << endl;
}

int main() {
    string s;
    while (cin >> s)
        solve(s);
    return 0;
}
