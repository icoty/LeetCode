#include "AllInclude.h"

class Solution {
    public:
        int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            set<pair<int, int>> st;
            for(int i = 0; i < obstacles.size(); ++i)
                st.insert(make_pair(obstacles[i][0], obstacles[i][1]));

            int maxValue = 0;
            int point[2] = {0, 0};  // 当前位置的坐标
            int dir = 1;            // 0: y, 1: -x, 2: -y, 3: x
            for(int i = 0; i < commands.size(); ++i)
            {
                if(-1 == commands[i])
                    dir = (3 + dir) % 4;
                else if(-2 == commands[i])
                    dir = (1 + dir) % 4;
                else
                {
                    int loc = -1;       // 0: x轴, 1: y轴
                    int forward = 1;   // 1:正方向, -1:夫方向
                    switch(dir)
                    {
                        case 0:
                            loc = 0;  forward = 1;      // +X
                            break;
                        case 1:
                            loc = 1;  forward = 1;
                            break;
                        case 2:
                            loc = 0;  forward = -1;     // -X
                            break;
                        case 3:
                            loc = 1;  forward = -1;
                            break;
                        default:
                            break;
                    }    
                    for(int m = 0; m < commands[i]; ++m)
                    {
                        point[loc] += forward;
                        if(0 != st.count(make_pair(point[0], point[1])))
                        {
                            point[loc] -= forward;
                            break;
                        }
                        int tmp = point[0] * point[0] + point[1] * point[1];
                        maxValue = max(maxValue, tmp);
                    }                 
                }           
            }
            return maxValue; 
        }
};
