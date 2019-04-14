#include "AllInclude.h"

/**
 *  * Definition for a point.
 *   * struct Point {
 *    *     int x;
 *     *     int y;
 *      *     Point() : x(0), y(0) {}
 *       *     Point(int a, int b) : x(a), y(b) {}
 *        * };
 *         */
class Solution {
    public:
        int maxPoints(vector<Point>& points) {
            if(points.size() <= 2)
                return points.size();

            int ret = 0;
            for(int i = 0; i < points.size(); ++i)
            {
                int cnt = 0;            // 统计重合的点数
                map<long double, int> mp;    // 统计相同斜率的点数
                for(int j = 0; j < points.size(); ++j)
                {
                    if(i == j)
                        continue;

                    if(points[i].x == points[j].x && points[i].y == points[j].y)
                    {
                        ++cnt;
                        continue;
                    }

                    long double flop = points[i].x == points[j].x ? INT_MAX : (points[i].y - points[j].y) / (long double)(points[i].x - points[j].x);
                    ++mp[flop];
                }

                if(mp.size() == 0)
                    mp[INT_MIN] = 0;

                for(auto ele : mp)
                {
                    ret = max(ret, ele.second + cnt);
                }            
            }
            return ret + 1;
        }
};
