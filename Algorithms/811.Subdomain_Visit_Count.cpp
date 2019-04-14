#include "AllInclude.h"

class Solution {
    public:
        void str2map(unordered_map<string, int>& mp, string str)
        {
            int space = str.find_first_of(' ', 0);
            int cnt = stoi(str.substr(0, space));

            str = str.substr(space + 1, str.size() - 1);
            mp[str] += cnt;

            int start = str.find_first_of('.', 0);
            while(str.npos != start)
            {
                str = str.substr(start + 1, str.size() - 1);
                mp[str] += cnt;
                start = str.find_first_of('.', 0);
            }
        }

        vector<string> subdomainVisits(vector<string>& cpdomains) {
            unordered_map<string, int> mp;
            vector<string> ret;
            for(auto ele: cpdomains)
            {
                str2map(mp, ele);
            }

            for(auto ele: mp)
            {
                ret.push_back(to_string(ele.second).append(1, ' ') + ele.first);
            }
            return ret;
        }
};
