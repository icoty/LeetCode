#include "AllInclude.h"

class Solution {
    public: // https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/183193/topic
        int minMoves(vector<int>& nums) {
            int sum = 0;
            int min = (1 << 31) - 1;
            for(auto ele: nums)
            {
                sum += ele;
                if(ele < min)
                    min = ele;
            }
            return sum - min * nums.size();
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().minMoves(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
