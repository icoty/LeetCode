#include "AllInclude.h"

class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            int minv = nums[nums.size() - 1];   //  从后往前遍历寻找乱序中的最小值,如果数组中的值比此最小值大,则记录下标保存到end。 
            int maxv = nums[0]; // 从前往后遍历寻找乱序中的最大值,如果数组中的值比此最大值小,则记录下标保存到start。 
            int start = -1; 
            int end = -2; 
            for(int i = 1; i < nums.size(); ++i){
                maxv = max(nums[i], maxv);
                minv = min(nums[i], minv);
                if(nums[i] < maxv)
                    end = i;
                if(nums[nums.size() - 1 - i] > minv)
                    start = nums.size() - 1 -i;
            }

            return end - start + 1; // 数组本身已经有序或长度为1时返回0
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

        int ret = Solution().findUnsortedSubarray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
