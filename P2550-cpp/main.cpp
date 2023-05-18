#include <iostream>

using namespace std;

int f[35], p[10]; // 定义时稍微大一点 防止溢出报错 可定义为bool

int main() {
    int n, m, count = 0; // count 计数用
    cin >> n;// n表示n张彩票
    for (int i = 1; i <= 7; i++) {
        cin >> m; // 彩票上的中奖号码 7个数（介于1和33之间的自然数，）
        f[m] = 1;
    }
    for (int i = 1; i <= n; i++) {
        count = 0;
        for (int i = 1; i <= 7; i++) {
            cin >> m;
            if (f[m]) { // 是中奖号码 count++
                count++;
            }
        }
        p[count]++; // 中几等奖的个数
    }
    for (int i = 7; i > 1; i--) {
        cout << p[i] << " ";
    }
    cout << p[1];
    return 0;
}
