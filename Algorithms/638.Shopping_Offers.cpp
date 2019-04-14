#include "AllInclude.h"

class Solution {
public:
    bool isValid(vector<int> & special, const vector<int>& needs){
        for(int i = 0; i < needs.size(); ++i){
            if(needs[i] < special[i])
                return false;
        }
        return true;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ret = 0;
        for(int i = 0; i < needs.size(); ++i){
            ret += price[i] * needs[i];
        }
        
        for(int i = 0; i < special.size(); ++i){
            if(isValid(special[i], needs)){
                vector<int> cur;
                for(int j = 0; j < needs.size(); ++j){
                    cur.push_back(needs[j] - special[i][j]);
                }
                int tmp = shoppingOffers(price, special, cur) + special[i][needs.size()];
                ret = min(ret, tmp);
            }
        }
        return ret;
    }
};
