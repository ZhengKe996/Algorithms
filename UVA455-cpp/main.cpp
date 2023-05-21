#include <iostream>

using namespace std;

int n, len, ans;
string s;

/**
 * 判断字符是否连续重复
 * @param T
 * @return
 */
bool isTrue(int T) {
    for (int i = 0; i + T < len; i++) {
        if (s[i] != s[i + T]) {
            return false;
        }
    }
    return true;
}


int main() {
    cin >> n; // 输入数据的组数
    while (n--) {
        cin >> s;
        len = s.length();
        ans = len;
        for (int T = 1; T < len; T++) {
            if (len % T == 0 && isTrue(T)) {
                ans = T;
                break; // 第一次找的一定是最小周期
            }
        }
        cout << ans << endl;
        if (n) {
            cout << endl;
        }
    }
    return 0;
}
