#include "AllInclude.h"

/*
class Employee {
    public:
        It's the unique ID of each node.
            unique id of this employee
            int id;
        the importance value of this employee
            int importance;
        the id of direct subordinates
            vector<int> subordinates;
};
*/

class Solution {
    public:
        void dfs(int id, int& sum, vector<pair<int, vector<int>>>& ds)
        {
            sum += ds[id].first;
            for(int i = 0; i < ds[id].second.size(); ++i)
                dfs(ds[id].second[i], sum, ds);
        }

        int getImportance(vector<Employee*> employees, int id) {
            int sum = 0;
            vector<pair<int, vector<int>>> id2info(2002); // id下标从1~2000
            for(auto ele: employees)
                id2info[ele->id] = {ele->importance, ele->subordinates};
            dfs(id, sum, id2info);
            return sum;
        }
};
