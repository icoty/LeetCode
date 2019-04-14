#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/4028713.html
        int maxProduct(vector<int>& nums) {
            int m = nums.size();
            if(m < 1)
                return 0;
            vector<int> f(m, 0);    // f[i]表示以i结尾的子数组最大乘积的值 
            vector<int> g(m, 0);    // g[i]表示以i结尾的子数组最小乘积的值,记录负数的情况 

            f[0] = nums[0];
            g[0] = nums[0];
            int ret = nums[0];
            for(int i = 1; i < m; ++i){
                f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
                g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
                ret = max(ret, f[i]);
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

        int ret = Solution().maxProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
