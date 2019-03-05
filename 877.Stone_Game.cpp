#include "AllInclude.h"

class Solution {
    public: // https://blog.csdn.net/androidchanhao/article/details/81271077
        bool stoneGame(vector<int>& piles) {
            vector< vector<int> > dp(piles.size(), vector<int>(piles.size(), 0));
            for(int i = 0; i < piles.size(); ++i)
                dp[i][i] = piles[i];

            for(int i = 1; i < piles.size(); ++i){
                for(int j = 0; j < piles.size() - i; ++j){
                    dp[j][j+i] = max(piles[j] - dp[j+1][j+i], piles[j+i] - dp[j][j+i-1]);
                }
            }

            return dp[0][piles.size() - 1] > 0;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> piles = stringToIntegerVector(line);

        bool ret = Solution().stoneGame(piles);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
