#include "AllInclude.h"

class Solution {
public:
#if 0. // debug
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<vector<int>> v(n, vector<int>(3, 0)); // start, end, id
        for(auto & ele : logs){
            int pos1 = ele.find_first_of(':');
            int pos2 = ele.find_last_of(':');
            int id = atoi(ele.substr(0, pos1).c_str());
            v[id][2] = id;
            if(ele[pos1 + 1] == 's')
                v[id][0] = atoi(ele.substr(pos2 + 1).c_str());
            else
                v[id][1] = atoi(ele.substr(pos2 + 1).c_str());
        }
        
        sort(v.begin(), v.end(), [](vector<int> & a, vector<int> & b){ return a[1] < b[1]; });
        vector<int> ret(n, 0);
        
        if(!v.empty())
            ret[v[0][2]] += v[0][1] - v[0][0] + 1;
        for(int i = 1; i < v.size(); ++i){
            ret[v[i][2]] += v[i - 1][0] - v[i][0] + v[i][1] - v[i - 1][1];
        }
        
        return ret;
    }
    
#else // pass  https://www.cnblogs.com/grandyang/p/7244767.html
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int preTime = 0, idx = 0, time = 0;
        char type[10];
        for (string log : logs) {
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &time);
            if (type[0] == 's') {
                if (!st.empty()) {
                    res[st.top()] += time - preTime;
                }
                st.push(idx);
            } else {
                res[st.top()] += ++time - preTime;
                st.pop();
            }
            preTime = time;
        }
        return res;
    } 
#endif
};
