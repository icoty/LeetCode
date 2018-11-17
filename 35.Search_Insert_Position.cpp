#include "AllInclude.h"

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if(0 == nums.size())
                return 0;
            int l = 0;
            int r = nums.size() - 1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(target == nums[mid])
                    return mid;
                else if(target < nums[mid])
                {
                    r = mid - 1;
                    if(target > nums[r])
                        return mid;                
                }
                else
                {
                    l = mid + 1;
                    if(target < nums[l])
                        return l;
                }
            }
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
        int target = stringToInteger(line);

        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
