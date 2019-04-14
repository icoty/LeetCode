#include "AllInclude.h"

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            bool row[9][9] = {false};   //  记录1~9行中的数字1~9是否出现过
            bool col[9][9] = {false};   //  记录1~9列中的数字1~9是否出现过
            bool box[9][9] = {false};   //  记录1~9个sub-box中的数字1~9是否出现过

            for(int i = 0; i < 9; ++i){
                for(int j = 0; j < 9; ++j){
                    if('.' != board[i][j]){
                        int num = board[i][j] - '0' - 1;    // 数字1~9转成0~8
                        int boxrow = i / 3 * 3 + j / 3;
                        if(row[i][num] || col[j][num] || box[boxrow][num])
                            return false;
                        else
                            row[i][num] = col[j][num] = box[boxrow][num] = true;
                    }
                }
            }
            return true;
        }
};
