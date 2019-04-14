#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/6181626.html
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            int ret = 0;
            int j = 0;
            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());
            for(int i = 0; i < houses.size(); ++i)
            {
                while(j < heaters.size() - 1 && abs(heaters[1+j] - houses[i]) <= abs(heaters[j] - houses[i]))
                    ++j;
                ret = max(ret, abs(heaters[j] - houses[i]));
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
        vector<int> houses = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> heaters = stringToIntegerVector(line);

        int ret = Solution().findRadius(houses, heaters);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
