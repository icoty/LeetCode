#include "AllInclude.h"

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int cnt5 = 0;
            int cnt10 = 0;
            int cnt20 = 0;
            for(int i = 0; i < bills.size(); ++i)
            {
                if(5 == bills[i]){
                    ++cnt5;
                }else if(10 == bills[i]){
                    --cnt5;
                    if(cnt5 < 0)
                        return false;
                    ++cnt10;
                }else{
                    if(0 == cnt5 || (0 == cnt10 && cnt5 < 3))
                        return false;
                    if(0 != cnt10){
                        --cnt10;
                        --cnt5;
                    }else{
                        cnt5 -= 3;
                    }
                    ++cnt20;
                }
            }
            return true;
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
        vector<int> bills = stringToIntegerVector(line);

        bool ret = Solution().lemonadeChange(bills);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
