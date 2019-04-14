#include "AllInclude.h"

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            if(nums.size() < 2)
                return false;
            unordered_map<int, int> mp;
            for(int i = 0; i < nums.size(); ++i){
                if(mp.size() < i + 1)
                    return true;
                ++mp[nums[i]];
            }

            return false;
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
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().containsDuplicate(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
