#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/6545075.html
        int findPairs(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            for(auto ele : nums)
                ++mp[ele];
            int ret = 0;
            for(auto ele : mp){
                if(0 == k && ele.second > 1)
                    ++ret;
                if(k > 0 && mp.count(ele.first + k))
                    ++ret;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().findPairs(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
