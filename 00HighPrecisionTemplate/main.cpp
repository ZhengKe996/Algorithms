#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 高精度加减法模版（C/C++）
 */

// 高精度加法 C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;

    int t = 0;// 进位
    for (int i = 0; i < A.size(); i++) {
        t += A[i];// 在A的范围+A
        if (i < B.size()) {
            t += B[i];// 在B的范围+B
        }
        C.push_back(t % 10);// 当前位只保留10的余数（0-9）
        t /= 10; // 进一位
    }
    if (t) {
        C.push_back(t);
    }
    return C;
}

/**
 * 判断 A是否>=B
 * @param A
 * @param B
 * @return
 */
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) { // 若位数不等  比较位数长度
        return A.size() > B.size();
    }

    // 若位数相等 比较各位大小
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true; // 默认返回ture
}


// 高精度减法 C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) { // 从个位开始 此处 A的size 一定大于B的size
        t = A[i] - t; // A[i]-B[i]-t;
        if (i < B.size()) {
            t -= B[i];
        }

        C.push_back((t + 10) % 10); // t>=0时 返回t；t<0 需要+10；
        if (t < 0) { // t<0 有进位；t>0 无进位
            t = 1;
        } else {
            t = 0;
        }
    }

    /**
     * 去掉前导0（高位前面的0）  如：003 则返回 3
     */
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}


int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;// a='123456'
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');// A=['6','5','4','3','2','1']
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }

    auto C = add(A, B); // auto 编译器自动推断类型
    // 加法 输出
    printf("加法输出：");
    for (int i = C.size() - 1; i >= 0; i--) {
        printf("%d", C[i]);
    }

    // 减法输出
    printf("\n减法输出：");
    if (cmp(A, B)) {
        auto D = sub(A, B);
        for (int i = D.size() - 1; i >= 0; i--) {
            printf("%d", D[i]);
        }
    } else {
        auto D = sub(B, A);
        for (int i = D.size() - 1; i >= 0; i--) {
            printf("%d", D[i]);
        }
    }


    return 0;
}
