#include "AllInclude.h"

class Solution {
    public:
        void backTrack(vector<int>& coins, int idx, int amount, int cnt, int& ret)
        {
            if(idx >= coins.size())
                return;
            if(0 == amount % coins[idx])
                ret = min(ret, cnt + amount / coins[idx]);

            for(int i = amount / coins[idx]; i >= 0; --i)
            {
                if(cnt + i > ret)
                    break;
                backTrack(coins, idx + 1, amount - i * coins[idx], cnt + i, ret);
            }
        }

        int coinChange(vector<int>& coins, int amount) {
            sort(coins.begin(), coins.end(), greater<int>());
            int ret = (1 << 31) - 1;
            backTrack(coins, 0, amount, 0, ret);
            return ret == (1 << 31) - 1 ? -1 : ret;
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
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);

        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
