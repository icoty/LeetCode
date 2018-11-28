#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/8343874.html
        int minCostClimbingStairs(vector<int>& cost) {  // cost[i]表示从第i个台阶跳到到下一台阶的代价
            vector<int> dp(cost.size() + 1, 0);

            for(int i = 0; i < dp.size(); ++i)
            {
                dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
            }
            return dp.back();
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
        vector<int> cost = stringToIntegerVector(line);

        int ret = Solution().minCostClimbingStairs(cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
