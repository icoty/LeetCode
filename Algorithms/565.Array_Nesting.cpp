#include "AllInclude.h"

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        vector<bool> flg(nums.size(), true);
        
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0;
            int tmp = nums[i];
            while(flg[tmp]){
                ++cnt;
                flg[tmp] = false;
                tmp = nums[tmp];
            }
            ret = max(ret, cnt);
        }
        return ret;
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
        
        int ret = Solution().arrayNesting(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}