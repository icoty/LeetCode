#include "AllInclude.h"

class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<int> path;
            path.push_back(0);
            dfs(graph, 0, graph.size() - 1, path);
            return ret;
        }

    private:
        void dfs(vector<vector<int>>& graph, int start, int end, vector<int> &path){
            if(start == end){
                ret.push_back(path);
            }else{
                for(auto & ele : graph[start]){
                    path.push_back(ele);
                    dfs(graph, ele, end, path);
                    path.pop_back();
                }
            }
        }

        vector<vector<int>> ret;
};
