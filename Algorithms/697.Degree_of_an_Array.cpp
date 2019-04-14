#include "AllInclude.h"

class Solution {
    public:
        int findShortestSubArray(vector<int>& nums) {
            unordered_map<int, int> freq;
            unordered_map<int, pair<int, int>> pos;
            int degree = 0;
            int ret = (1 << 31) - 1;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(1 == ++freq[nums[i]]){
                    pos[nums[i]] = make_pair(i, i);
                }else{
                    pos[nums[i]].second = i;
                }
                degree = max(degree, freq[nums[i]]);
            }

            for(auto ele: freq)
                if(degree == ele.second)
                {
                    ret = min(ret, pos[ele.first].second - pos[ele.first].first + 1);
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
