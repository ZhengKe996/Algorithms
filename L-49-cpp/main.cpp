#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 方法一：让同一组的字符串具有相同的 Hash 函数值，不同组的字符串具有不同的 Hash 函数值
     * @param strs
     * @return
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        for (string &s: strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            if (groups.find(copy) == groups.end()) {
                groups[copy] = {};
            }
            groups[copy].push_back(s);
        }
        vector<vector<string >> ans;
        for (const pair<string, vector<string>> &group: groups) {
            ans.push_back(group.second);
        }
        return ans;

    }

private:
    unordered_map<string, vector<string>> groups;

};

int main() {
    Solution s;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << endl;
        }
    }
    return 0;
}
