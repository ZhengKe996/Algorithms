#include <iostream>

using namespace std;

int main() {
    int k, sub1, sub2, sub3;
    bool flag = 0;
    cin >> k;
    for (int i = 10000; i <= 30000; i++) {
        sub1 = i / 100;
        sub2 = (i / 10) % 1000;
        sub3 = i % 1000;

        if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
            flag = 1;
            cout << i << endl;
        }
    }
    if (!flag) {
        cout << "No" << endl;
    }
    return 0;
}
