#include <iostream>

using namespace std;
const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

/**
 *  二维前缀和
    S[i, j] = 第i行j列格子左上部分所有元素的和
    以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
    S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]

    3 4 3
    1 7 2 4
    3 6 2 8
    2 1 2 3
    1 1 2 2
    2 1 3 4
    1 3 3 4

    17
    27
    21
 */

int main() {

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 运算
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }


    return 0;
}
