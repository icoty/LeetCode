#include "AllInclude.h"

/*
 *     1.根据三个点求面积参考：https://blog.csdn.net/joker_yy/article/details/80030886
 *     2.暴力破解, 也可求土包, 在遍历凸包上的点求最大面积
 *   
 *   
 */
class Solution {
    public: 
        double largestTriangleArea(vector<vector<int>>& points) {
            double max_area = 0.0;
            double area = 0.0;
            for(auto &p1 : points) { 
                for(auto &p2 : points) {
                    for(auto &p3 : points) {
                        area = abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - 
                                p2[0] * p1[1] - p3[0] * p2[1] - p1[0] * p3[1]) / 2.0;
                        max_area = max(max_area, area);
                    }
                }
            }
            return max_area;
        }
};
