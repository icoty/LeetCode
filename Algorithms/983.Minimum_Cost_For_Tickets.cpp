#include "AllInclude.h"

class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            vector<int> dp(366, 0);
            for(int i = 0; i < days.size(); ++i){
                dp[days[i]] = 1;
            }

            for(int i = 1; i < 366; ++i){
                if(dp[i] == 0){
                    dp[i] = dp[i - 1];
                }else{
                    dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
                }
            }

            return dp[365];
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
        vector<int> days = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> costs = stringToIntegerVector(line);

        int ret = Solution().mincostTickets(days, costs);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
