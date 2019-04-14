#include "AllInclude.h"

class Solution {
public: // https://www.cnblogs.com/liujinhong/p/6206792.html
#if 0
    int xvalbit1(int num){
        int cnt = 0;
        for(int i = 31; i >= 0; --i)
            cnt += (num >> i) & 0x1;
        return cnt;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                ret += xvalbit1(nums[i] ^ nums[j]);
            }
        }
        return ret;
    }
#else
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0;
        for(int j = 0; j < 32; ++j){
            int bit1 = 0;
            for(int i = 0; i < nums.size(); ++i){
                bit1 += (nums[i] >> j) & 1;
            }
            ret += bit1 * (nums.size() - bit1);
        }
        return ret;
    }   
#endif
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
        
        int ret = Solution().totalHammingDistance(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
