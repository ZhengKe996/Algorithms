#include <iostream>
#include <cstring>

using namespace std;
bool field[240 + 5][240 + 5];

void ex(int x, int y, int s, int t) {
    // 行：x->s 列：y->t
    for (int i = x; i <= s; i++) {
        for (int j = y; j <= t; j++) {
            field[i][j] = 1;
        }
    }
}

int main() {
    int m, n, c; // m行 n列 c个数
    int x, y, s, t, count = 0;
    memset(field, 0, sizeof(field)); // c风格的函数需要声明 cstring；  filed[][] 初始化为0
    cin >> m >> n >> c;
    for (int i = 0; i < c; i++) {
        cin >> x >> y >> s >> t;
        ex(x, y, s, t);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (field[i][j]) {
                count++;
            }
        }
    }

    cout << count;
    return 0;
}
