#include <iostream>

using namespace std;

bool g[10000][10000];
int n, m, k;
int x, y;


/**
 * 光照范围
 * @param x 横坐标
 * @param y 纵坐标
 * @param t 范围
 */
void light(int x, int y, int t) {
    for (int i = x - t; i <= x + t; i++) {
        for (int j = y - t; j <= y + t; j++) {
            if (i > n || i < 1 || j > n || j < 1) {
                continue; // 超出范围 跳出本次循环
            } else {
                g[i][j] = 1; // 点亮
            }
        }
    }
}

/**
 * 萤石的光照范围 （2*2）
 * @param x
 * @param y
 */
void ys(int x, int y) {
    light(x, y, 2);
}

/**
 * 火把的光照范围 （区别 参数不一样）
 * @param x
 * @param y
 */
void hb(int x, int y) {
    light(x, y, 1);
    if (x + 2 <= n) {
        g[x + 2][y] = 1;
    }
    if (x - 2 > 0) {
        g[x - 2][y] = 1;
    }
    if (y + 2 <= n) {
        g[x][y + 2] = 1;
    }
    if (y - 2 > 0) {
        g[x][y - 2] = 1;
    }
}


int count() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == 0) { cnt++; }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y, hb(x, y);
    }
    for (int i = 1; i <= k; i++) {
        cin >> x >> y, ys(x, y);
    }
    cout << count();
    return 0;
}