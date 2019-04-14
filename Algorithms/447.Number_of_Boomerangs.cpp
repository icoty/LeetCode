#include "AllInclude.h"

class Solution {
    public:
        int dis(pair<int, int> one, pair<int, int> another)
        {
            return pow((one.first - another.first), 2) + pow((one.second - another.second), 2);
        }
        int numberOfBoomerangs(vector<pair<int, int>>& points) {
            int ret = 0;
            for(int i = 0; i < points.size(); ++i)
            {
                unordered_map<int, int> mp;
                for(int j = 0; j < points.size(); ++j)
                {
                    if(i == j)
                        continue;
                    ++mp[dis(points[i], points[j])];
                }

                for(auto ele: mp)
                {
                    ret += ele.second * (ele.second - 1);
                }
            }
            return ret;
        }
};
