#include <iostream>
#include <string>

using namespace std;

string s;
string mir = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
string ans[4] = {"not a palindrome.", "a regular palindrome.", "a mirrored string.", "a mirrored palindrome."};


char rev(char ch) {
    if (isalpha(ch)) {
        return mir[ch - 'A'];
    } else {
        return mir[ch - '0' + 25];
    }
}


int main() {
    while (cin >> s) {
        int len = s.length();
        bool p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (s[i] != s[len - i - 1]) {
                p = 0;
            }
            if (rev(s[i]) != s[len - i - 1]) {
                m = 0;
            }
        }
        cout << s << " -- is " << ans[m * 2 + p] << endl << endl;
    }
    return 0;
}
