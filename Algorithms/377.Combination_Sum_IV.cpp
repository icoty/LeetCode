#include "AllInclude.h"

class Solution {
    public: //  http://www.cnblogs.com/grandyang/p/5705750.html 
        int combinationSum4(vector<int>& nums, int target) {
            vector<int> dp(target+1);
            dp[0] = 1;
            for(int i = 1; i <= target; ++i)
            {
                for(auto ele : nums)
                {
                    if(i >= ele)
                        dp[i] += dp[i - ele];
                }
            }
            return dp[target];
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().combinationSum4(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
