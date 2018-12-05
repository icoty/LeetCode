#include "AllInclude.h"

class Solution {
    public: // https://www.cnblogs.com/grandyang/p/4217175.html 寻找局部极大值
        int findPeakElement(vector<int>& nums) {
            if(1 == nums.size())
                return 0;
            int l = 0;
            int r = nums.size() - 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(nums[mid] > nums[mid + 1])
                    r = mid;
                else
                    l = mid + 1;
            }
            return l;
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

        int ret = Solution().findPeakElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
