#include "AllInclude.h"

class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            vector<int> st(20001, 0);
            for(auto ele: nums)
                ++st[ele + 10000];
            int sum = 0;
            bool flg = false;
            for(int i = 0; i < st.size(); ++i)
            {
                if(0 == st[i])
                    continue;
                if(flg)
                    --st[i];
                if(0 != st[i] % 2)
                    flg = true;
                else 
                    flg = false;
                sum += ((st[i] + 1) / 2) * (i - 10000);
            }
            return sum;
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

        int ret = Solution().arrayPairSum(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
