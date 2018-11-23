#include "AllInclude.h"

// https://www.cnblogs.com/grandyang/p/6222149.html
class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            if(nums.size() < 1)
                return {};
            vector<int> ret;
            for(int i = 0; i < nums.size(); ++i)
            {
                int index = abs(nums[i]) - 1;
                if(nums[index] > 0) // 将所有出现过的数nums[i]应该存放的正确位置标记为负,表示nums[i]已经出现过。对于未出现过的数,其应该被正确存放的位置永远不会被修改
                    nums[index] = -nums[index];
            }

            for(int j = 0; j < nums.size(); ++j)
                if(nums[j] > 0)
                    ret.push_back(j+1);
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        vector<int> ret = Solution().findDisappearedNumbers(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
