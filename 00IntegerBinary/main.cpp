#include <iostream>

using namespace std;

/* 整数二分 */

bool check(int mid) {
    return true;
}

int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid - 1;
        }

    }
    return l;
}

/**
 * 演示
 * @return
 */
const int N = 100010;
int m, n;
int q[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    while (m--) {
        int x;
        scanf("%d", &x);
        //模板二，找出的是第一个满足>=x性质的数
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        // 整个数组中都不包含x这个元素
        if (q[l] != x) cout << "-1 -1" << endl;
        else {
            cout << l << " ";
            int l = 0, r = n - 1;
            // 模板一，查找满足<=x性质的右边界
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;

}
