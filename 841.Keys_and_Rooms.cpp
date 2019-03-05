#include "AllInclude.h"

class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            if(rooms.size() == 1)
                return true;
            vector<bool> bl(rooms.size(), false); 
            bl[0] = true;
            int cnt = 1;
            dfs(rooms, 0, bl, cnt);

            return cnt == rooms.size();
        }

        void dfs(vector<vector<int>>& rooms, int start, vector<bool>& bl, int& cnt){
            for(int i = 0; i < rooms[start].size(); ++i){
                if(bl[rooms[start][i]])
                    continue;
                ++cnt;
                bl[rooms[start][i]] = true;
                dfs(rooms, rooms[start][i], bl, cnt);
            }
            return;
        }
};
