#include "AllInclude.h"

class Solution {
    public: //  http://www.cnblogs.com/grandyang/p/4484571.html 有向图bfs dfs应用
        bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<vector<int>> edge(numCourses, vector<int>(0));
            vector<int> in(numCourses, 0);

            for(auto ele : prerequisites)
            {
                edge[ele.second].push_back(ele.first); // 记录ele[1]的所有出度
                ++in[ele.first];   // ele[0]的入度+1
            }

            queue<int> q;
            for(int i = 0; i < numCourses; ++i){
                if(0 == in[i])
                    q.push(i);  // 从入度为0的点BFS
            }

            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                for(auto ele : edge[tmp]){
                    --in[ele];
                    if(0 == in[ele]) 
                        q.push(ele);
                }          
            }
            for(int i = 0; i < numCourses; ++i){
                if(0 != in[i]) 
                    return false;
            }
            return true;
        }
};
