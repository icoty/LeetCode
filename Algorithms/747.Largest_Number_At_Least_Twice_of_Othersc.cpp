#include "AllInclude.h"

class Solution {
    public: // 只需判断第二大的数是否满足条件即可
        int dominantIndex(vector<int>& nums) {
            int fir = 1 << 31;
            int sec = 1 << 31;
            int index = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(fir < nums[i])
                {
                    sec = fir;
                    fir = nums[i];
                    index = i;
                }

                if(sec < nums[i] && nums[i] < fir)
                    sec = nums[i];
            }

            return fir >= 2 * sec ? index : -1;
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

        int ret = Solution().dominantIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
