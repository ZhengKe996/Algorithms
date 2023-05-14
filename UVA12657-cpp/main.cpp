#include <iostream>

using namespace std;

/**
 * 使用静态链表
 */

int r[100000 + 5], l[100000 + 5];

/**
 * 初始化化一个链表
 * @param n
 */
void init(int n) {
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1;
        r[i] = (i + 1) % (n + 1);
    }
    r[0] = 1;
    l[0] = n;
}

/**
 * 链表连接操作
 * @param L
 * @param R
 */
void link(int L, int R) {
    r[L] = R; // 前驱
    l[R] = L; // 后继
}


int main() {
    int n, m, a, x, y, k = 0;
    bool flag;
    while (cin >> n >> m) {
        flag = false;
        init(n);
        for (int i = 0; i < m; i++) {
            cin >> a;
            if (a == 4)
                flag = !flag;// 翻转
            else {
                cin >> x >> y;
                if (a == 3 && r[y] == x) {
                    swap(x, y); // y是x的后继（x在y的右侧 处理成 x在y的左侧）
                }
                if (a != 3 && flag) { // 翻转过且 a!=3的情况
                    a = 3 - a; // a=1 3-a=2 执行2号指令； a=2 3-a=1 执行1号指令
                }
                if (a == 1 && x == l[y]) { // 如果x本来就在y的左侧 忽略操作
                    continue;
                }
                if (a == 2 && x == r[y]) { // 如果x本来就在y的右侧 忽略操作
                    continue;
                }

                int Lx = l[x], Rx = r[x], Ly = l[y], Ry = r[y]; // 读取x，y的前驱后继
                if (a == 1) {
                    // 『LX X RX，LY Y RY 』-> 『LX RX，LY X Y RY 』
                    link(Lx, Rx);// 删除x
                    link(Ly, x);
                    link(x, y);//x插入y
                } else if (a == 2) {
                    // 『LX X RX，LY Y RY 』-> 『LX RX，LY Y  X RY 』
                    link(Lx, Rx);//删除x
                    link(y, x);
                    link(x, Ry);//x插入y右
                } else if (a == 3) {
                    if (r[x] == y) {
                        // 『LX X Y RY 』-> 『LX Y X RY 』
                        link(Lx, y);
                        link(y, x);
                        link(x, Ry);
                    } else {
                        // 『LX X RX，LY Y RY 』-> 『LX Y RX , LY X RY 』
                        link(Lx, y); // 交换位置
                        link(y, Rx);
                        link(Ly, x);
                        link(x, Ry);
                    }
                }
            }
        }
        int t = 0;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            t = r[t];
            if (i % 2 == 1)
                sum += t;
        }
        if (flag && n % 2 == 0)
            sum = (long long) n * (n + 1) / 2 - sum;
        cout << "Case " << ++k << ": " << sum << endl;
    }
    return 0;
}
