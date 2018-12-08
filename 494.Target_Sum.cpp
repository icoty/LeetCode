#include "AllInclude.h"

class Solution {
    public:
        void bfs(vector<int>& nums, int idx, int target)
        {
            if(idx >= nums.size() && 0 == target)
                ++ret;
            else if(idx >= nums.size() && 0 != target)
                return;
            else{
                bfs(nums, idx + 1, target - nums[idx]);
                bfs(nums, idx + 1, target + nums[idx]);
            }

        }

        int findTargetSumWays(vector<int>& nums, int S) {
            bfs(nums, 0, S);
            return ret;
        }
    private:
        int ret = 0;
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
        int S = stringToInteger(line);

        int ret = Solution().findTargetSumWays(nums, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
