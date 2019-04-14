#include "AllInclude.h"

class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int i = 0;
            while(i < flowerbed.size() && 1 != flowerbed[i])
                ++i;

            int ret = i == flowerbed.size() ? (1 + i) / 2 : i / 2;
            int cnt = 0;
            int j = i + 1;
            for(; j < flowerbed.size(); ++j)
            {
                if(0 == flowerbed[j])
                    ++cnt;
                else
                {
                    ret += (cnt - 1) / 2;
                    cnt = 0;
                }
            }

            if(cnt > 0)
                ret += cnt / 2;
            return ret >= n;
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
        vector<int> flowerbed = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);

        bool ret = Solution().canPlaceFlowers(flowerbed, n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
