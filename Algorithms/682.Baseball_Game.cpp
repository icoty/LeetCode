#include "AllInclude.h"

class Solution {
    public:
        int calPoints(vector<string>& ops) {
            vector<int> point;
            int sum = 0;
            for(auto ele: ops)
            {
                if("D" == ele){
                    sum += 2*point.back();
                    point.push_back(2*point.back());
                }else if("C" == ele){
                    sum -= point.back();
                    point.pop_back();
                }else if("+" == ele){
                    sum += point.back() + point[point.size() - 2];
                    point.push_back(point.back() + point[point.size() - 2]);
                }else{
                    sum += stoi(ele);
                    point.push_back(stoi(ele));
                }
            }
            return sum;
        }
};
