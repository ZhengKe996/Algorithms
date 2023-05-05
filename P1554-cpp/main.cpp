#include <iostream>

using namespace std;

int main() {
    int m, n, a[1001];
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        int j = i;
        while (j > 0) {// 循环
            a[j % 10]++;
            j /= 10;// 更新j的值
        }
    }
    for (int i = 0; i <= 9; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
