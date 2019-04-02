#include "AllInclude.h"

class Solution {
public:
    int getMinutes(string& s1, string& s2, bool last = false){
        int h1 = atoi(s1.substr(0, 2).c_str());
        int h2 = atoi(s2.substr(0, 2).c_str());
        int m1 = atoi(s1.substr(3).c_str());
        int m2 = atoi(s2.substr(3).c_str());
        cout << h1 << " "<<h2 <<" "<<m1 <<" "<<m2;
        if(last)
            return 24*60 + h2*60 + m2 - h1*60 - m1;
        else
            return (h2 -h1) * 60 + m2 - m1;
    }
    
    int findMinDifference(vector<string>& tp) {
        sort(tp.begin(), tp.end());
        int ret = getMinutes(tp.back(), tp.front(), true);
        
        for(int i = 0; i < tp.size() - 1; ++i){
            ret = min(ret, getMinutes(tp[i], tp[i + 1], false));
        }
        return ret;
    }
};
