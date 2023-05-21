#include <iostream>
#include <string>

using namespace std;
int n, len;
string s;

/**
 * 比较最小的开始位置
 * @param p
 * @param q
 * @return
 */
bool les(int p, int q) {
    for (int j = 0; j < len; j++) {
        if (s[p + j] != s[q + j]) {
            return s[p + j] < s[q + j];
        }
    }
    return 0;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        len = s.length();
        string mins = s;
        int ans = 0;
        s += s;

        for (int j = 1; j < len; j++)
            if (les(j, ans)) {
                ans = j;
            }
        mins = s.substr(ans, len);
        cout << mins << endl;
    }
    return 0;
}
