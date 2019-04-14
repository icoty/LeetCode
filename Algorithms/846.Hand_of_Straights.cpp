#include "AllInclude.h"

class Solution {
public: // https://blog.csdn.net/fuxuemingzhu/article/details/82530857
    bool isNStraightHand(vector<int>& h, int W) {
        map<int, int> mp;
        for(auto & ele : h)
            ++mp[ele];

        for(auto & ele : mp){
            int start = ele.first;
            int cnt = ele.second;
            if(cnt > 0){
                for(int i = 1; i < W; ++i){
                    if(!mp.count(start + i))
                        return false;
                    mp[start + i] -= cnt;
                    if(mp[start + i] < 0)
                        return false;
                }
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> hand = stringToIntegerVector(line);
        getline(cin, line);
        int W = stringToInteger(line);
        
        bool ret = Solution().isNStraightHand(hand, W);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
