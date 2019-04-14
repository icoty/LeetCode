#include "AllInclude.h"

class Solution {
public: //https://blog.csdn.net/cuihaolong/article/details/61917646
    vector<vector<int>> round = {{-1, -1}, {-1, 0}, {-1, +1}, {0, -1}, {0, +1}, {+1, -1}, {+1, 0}, {+1, +1}};
    vector<char> val = {'B', '1', '2', '3', '4', '5', '6', '7', '8'};
    
    void dfs(vector<vector<char>>& bd, int r, int c){
        if(r < 0 || r >= bd.size() || c < 0 || c >= bd[0].size())
            return;
        
        if(bd[r][c] == 'E'){
            int cnt = 0;
            for(auto & ele : round){
                int tr = r + ele[0];
                int tc = c + ele[1];
                if(tr >= 0 && tr < bd.size() && tc >= 0 && tc < bd[0].size() && bd[tr][tc] == 'M'){
                    ++cnt;
                }
            }
            bd[r][c] = val[cnt];
            
            if(bd[r][c] == 'B'){
                for(auto & ele : round){
                    dfs(bd, r + ele[0], c + ele[1]);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& bd, vector<int>& cl) {
        if(bd[cl[0]][cl[1]] == 'M'){
            bd[cl[0]][cl[1]] = 'X';
            return bd;
        }
        
        dfs(bd, cl[0], cl[1]);
        return bd;
    }
};
