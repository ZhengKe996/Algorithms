#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 高精度乘低精度  C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0;

    for (int i = 0; i < A.size(); i++) {
        if (i < A.size()) {
            t += A[i] * b;
        }
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) { // 去除前导0
        C.pop_back();
    }

    return C;
}


// 高精度除以低精度 A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) { // 从高位开始
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0'); // a[i]-'0' 转数字 ASCII相减
    }

    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--) {
        printf("%d", C[i]);
    }

    cout << endl;

    int r;
    auto D = div(A, b, r);
    for (int i = D.size() - 1; i >= 0; i--) {
        printf("%d", D[i]);
    }
    cout << endl << r << endl;

    return 0;
}
