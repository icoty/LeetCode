#include "AllInclude.h"

class Solution {
    public:
        vector<vector<string>> findDuplicate(vector<string>& paths) {
            vector<vector<string>> res;
            unordered_map<string, vector<string>> m;
            for (string path : paths) {
                istringstream is(path);
                string pre = "", t = "";
                is >> pre;
                while (is >> t) {
                    int idx = t.find_last_of('(');
                    string dir = pre + "/" + t.substr(0, idx);
                    string content = t.substr(idx + 1, t.size() - idx - 2);
                    m[content].push_back(dir);
                }
            }
            for (auto a : m) {
                if (a.second.size() > 1)
                    res.push_back(a.second);
            }
            return res;
        }
};
