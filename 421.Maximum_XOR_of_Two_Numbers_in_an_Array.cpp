#include "AllInclude.h"

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ret = 0;
        vector<int> v0, v1;
        for(int i = 31; i >= 0; --i){
            v0.clear();
            v1.clear();
            for(auto & ele : nums){
                if(ele & (0x1 << i))
                    v1.push_back(ele);
                else
                    v0.push_back(ele);
            }
            
            if(!v0.empty() && !v1.empty()){
                ret += (0x1 << i);
                ret += help(v0, v1, i - 1);
                break;
            }
        }
        
        return ret;
    }
    
    int help(vector<int>& v0, vector<int>& v1, int pos){
        if(pos < 0)
            return 0;
        vector<int> v00;
        vector<int> v01;
        vector<int> v10;
        vector<int> v11;
        int tmp01 = 0, tmp10 = 0;
        
        for(auto & ele : v0){
            if(ele & (0x1 << pos))
                v01.push_back(ele);
            else
                v00.push_back(ele);      
        }
        
        for(auto & ele : v1){
            if(ele & (0x1 << pos))
                v11.push_back(ele);
            else
                v10.push_back(ele);      
        }

        if(!v00.empty() && !v11.empty()){
            tmp01 = (0x1 << pos) + help(v00, v11, pos - 1);
        }
        
        if(!v01.empty() && !v10.empty()){
            tmp10 = (0x1 << pos) + help(v01, v10, pos - 1);
        }
        
        return (tmp01 || tmp10) ? max(tmp10, tmp01) : help(v0, v1, pos - 1);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMaximumXOR(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
