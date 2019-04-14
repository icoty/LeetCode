#include "AllInclude.h"

class Solution {
    public:
        int regionsBySlashes(vector<string>& grid) {
            int ret = 0;
            vector<vector<int> > g(3 * grid.size(), vector<int>(3 * grid.size(), 0));
            for(auto i = 0; i < grid.size(); ++i)
                for(auto j = 0; j < grid.size(); ++j){
                    if(grid[i][j] == '/')
                        g[i*3 + 2][j*3] = g[i*3 + 1][j*3 + 1] = g[i*3][j*3 + 2] = 1;
                    if(grid[i][j] == '\\')
                        g[i*3][j*3] = g[i*3 + 1][j*3 + 1] = g[i*3 + 2][j*3 + 2] = 1;
                }

            for(auto i = 0; i < g.size(); ++i)
                for(auto j = 0; j < g.size(); ++j)
                    if(0 == g[i][j])
                        dfs(g, i, j), ++ret;    // 逗号表达式

            return ret;
        }

    private:
        void dfs(vector<vector<int> >& g, int i, int j){
            if(i >= 0 && j >= 0 && i < g.size() && j < g.size() && g[i][j] == 0){
                g[i][j] = 1;
                dfs(g, i - 1, j), dfs(g, i + 1, j), dfs(g, i, j - 1), dfs(g, i, j + 1);
            }
        }
};
