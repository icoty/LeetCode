#include "AllInclue.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/7565424.html
        bool checkPossibility(vector<int>& nums) {
            int cnt = 1;
            for(int i = 1; i < nums.size(); ++i)
            {
                if(nums[i - 1] > nums[i]){
                    if(0 == cnt)
                        return false;
                    if(1 == i || nums[i - 2] < nums[i])
                        nums[i - 1] = nums[i];
                    else
                        nums[i] = nums[i - 1];
                    --cnt;
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
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().checkPossibility(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
