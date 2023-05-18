#include <iostream>

using namespace std;

const int size2 = 10002;
int x1[size2], y11[size2], x2[size2], y2[size2]; // 轰炸区域的坐标（可以使用一维数组+结构体）

int main() {
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y; // 第一行输入 4 个整数 x指x轮轰炸  y指测试目标点个数
    for (int i = 0; i < x; i++) {
        cin >> x1[i] >> y11[i] >> x2[i] >> y2[i]; // 输入轰炸区域左上角 右下角坐标
    }

    int count = 0, last = 0; // count 计数 last 记录最后一次轰炸是第几轮
    for (int i = 0; i < y; i++) {
        cin >> a >> b; //
        count = 0;
        for (int j = 0; j < x; j++) {
            if (a >= x1[j] && a <= x2[j] && b >= y11[j] && b <= y2[j]) { // 是否在轰炸范围内
                count++;
                last = j;
            }
        }
        if (!count) { // 没有被炸掉输出 N
            cout << "N" << endl;
        } else {
            cout << "Y " << count << " " << ++last << endl;
        }
    }
    return 0;
}
