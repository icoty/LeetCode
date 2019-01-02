#include "AllInclude.h"

class Solution {
    public: 
#if 0
        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
            map<int, int> tmp;
            for(int i = 0; i < buildings.size(); ++i){
                int j = buildings[i][0];
                for(; j < buildings[i][1]; ++j){
                    if(!tmp.count(j))
                        tmp[j] = buildings[i][2];
                    else if(tmp[j] < buildings[i][2])
                        tmp[j] = buildings[i][2];
                }
                tmp[j] = 0;
            }

            for(auto ele : tmp){
                int cnt = 1;
                while(tmp.count(ele.first + cnt) && ele.second == tmp[ele.first + cnt])
                    tmp.erase(ele.first + cnt++);
            }
            vector<pair<int, int>> ret(tmp.begin(), tmp.end());
            return ret;
        }
#else       // https://www.cnblogs.com/grandyang/p/4534586.html
        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
            vector<pair<int, int>> h, res;
            multiset<int> m;
            int pre = 0, cur = 0;
            for (auto &a : buildings) {
                h.push_back({a[0], -a[2]});
                h.push_back({a[1], a[2]});
            }
            sort(h.begin(), h.end());
            m.insert(0);
            for (auto &a : h) {
                if (a.second < 0) m.insert(-a.second);
                else m.erase(m.find(a.second));
                cur = *m.rbegin();
                if (cur != pre) {
                    res.push_back({a.first, cur});
                    pre = cur;
                }
            }
            return res;
        }
#endif
};
