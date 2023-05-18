#include<iostream>
#include<deque>
#include<map>

using namespace std;

int execlines[1010], n, t, t1, t2, t3, t4, t5, q;
vector<string> prog[1010];
deque<int> wait;
deque<int> stop;

int main() {
    ios::sync_with_stdio(0);
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    cin >> t;
    for (int e = 0; e < t; ++e) {
        if (e) cout << endl;
        cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> q;
        map<string, int> vars;
        bool locked = 0;
        memset(execlines, 0, sizeof(execlines));
        for (int i = 0; i < 1010; ++i) prog[i].clear();
        string line;
        getline(cin, line);
        for (int i = 1; i <= n; ++i) {
            wait.push_back(i);
            while (1) {
                getline(cin, line);
                if (line == "end") break;
                prog[i].push_back(line);
            }
        }
        while (!wait.empty()) {
            int id = wait.front(), peie = q;
            wait.pop_front();
            string cmd;
            while (execlines[id] < prog[id].size()) {
                stringstream ss(prog[id][execlines[id]]);
                ss >> cmd;
                // cout << "    " << id << ' ' << prog[id][execlines[id]] << endl;
                if (cmd == "print") {
                    string var;
                    ss >> var;
                    cout << id << ": " << vars[var] << endl;
                    peie -= t2;
                } else if (cmd == "lock") {
                    if (locked) {
                        stop.push_back(id);
                        break;
                    }
                    locked = 1;
                    peie -= t3;
                } else if (cmd == "unlock") {
                    locked = 0;
                    if (!stop.empty()) {
                        wait.push_front(stop.front());
                        stop.pop_front();
                    }
                    peie -= t4;
                } else {
                    string var = cmd;
                    ss >> cmd;
                    int val;
                    ss >> val;
                    vars[var] = val;
                    peie -= t1;
                }
                ++execlines[id];
                if (peie < 1) {
                    wait.push_back(id);
                    break;
                }
            }
        }
    }
    return 0;
}