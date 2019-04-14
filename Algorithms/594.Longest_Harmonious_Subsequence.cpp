#include "AllInclude.h"

class Solution {
    public:
        int findLHS(vector<int>& nums) {
            int ret = 0;
            unordered_map<int, int> mp;
            for(auto ele : nums)
                ++mp[ele];
            for(auto ele : mp)
                if(mp.count(ele.first + 1))
                    ret = max(ret, ele.second + mp[ele.first + 1]);
            return ret;
        }

#if 0
        int findLHS(vector<int>& nums) {
            int ret = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                int cnt0 = 0;   //  差值为0
                int cnt1 = 0;   //  差值为1
                int cnt2 = 0;   //  差值为-1
                for(int j = 0; j < nums.size(); ++j)
                {
                    if(0 == nums[j] - nums[i])
                        ++cnt0;
                    else if(1 == nums[j] - nums[i])
                        ++cnt1;
                    else if(-1 == nums[j] - nums[i])
                        ++cnt2;
                }
                if(0 != cnt1 || 0 != cnt2)
                    ret = max(ret, max(cnt0 + cnt2, cnt0 + cnt1));
            }
            return ret;
        }
#endif
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

        int ret = Solution().findLHS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
