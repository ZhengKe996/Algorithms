#include <iostream>

using namespace std;

int main() {
    int n;
    string x, y, res;
    cin >> n;
    cin >> x;
    cin >> y;

    for (int i = 0; i < n; i++) {
        if (x[i] < y[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << y;

    return 0;
}
