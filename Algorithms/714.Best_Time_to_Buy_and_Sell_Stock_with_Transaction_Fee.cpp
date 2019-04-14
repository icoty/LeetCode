#include "AllInclude.h"

class Solution {
public: // https://blog.csdn.net/fuxuemingzhu/article/details/79888528
    int maxProfit(vector<int>& p, int f) {
        int cash = 0;
        int hold = -p[0];
        for(int i = 1; i < p.size(); ++i){
            cash = max(cash, hold + p[i] - f);
            hold = max(hold, cash - p[i]);
        }
        
        return cash;
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
        vector<int> prices = stringToIntegerVector(line);
        getline(cin, line);
        int fee = stringToInteger(line);
        
        int ret = Solution().maxProfit(prices, fee);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
