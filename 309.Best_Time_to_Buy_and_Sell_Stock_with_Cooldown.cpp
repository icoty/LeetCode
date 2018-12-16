#include "AllInclude.h"

class Solution {
    public: //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75957/An-8ms-C%2B%2B-DP-solution-easy-to-understand
        int maxProfit(vector<int>& p) {
            int m = p.size();
            if(m < 2)
                return 0;
            int b0 = -p[0]; // b[i - 2]
            int s0 = 0;     // s[i - 2]
            int b1 = b0 + p[0] - p[1];  // b[i - 1]
            int s1 = max(b0 + p[1], s0 - p[0] + p[1]);  // s[i - 1]
            int ret = max(0, s1);
            for(int i = 2; i < m; ++i){
                int si = max(b1 + p[i], s1 - p[i - 1] + p[i]);      // s[i]
                int bi = max(b1 + p[i - 1] - p[i], s0 - p[i]);  // b[i]
                if(ret < si)
                    ret = si;
                s0 = s1;
                s1 = si;
                b1 = bi;
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
        vector<int> prices = stringToIntegerVector(line);

        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
