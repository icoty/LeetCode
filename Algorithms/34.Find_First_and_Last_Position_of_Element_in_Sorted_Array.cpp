#include "AllInclude.h"

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size() - 1;
            vector<int> ret = {-1, -1};
            while(l <= r){
                int mid = l + (r - l ) / 2;
                if(nums[mid] == target)
                {
                    ret[0] = mid;
                    ret[1] = mid;
                    while(ret[0] > 0 && nums[ret[0]] == nums[ret[0] - 1])
                        --ret[0];
                    while(ret[1] < nums.size() - 1 && nums[ret[1]] == nums[ret[1] + 1])
                        ++ret[1];
                    return ret;
                }else if(nums[mid] < target){
                    l = mid + 1;
                }else
                    r = mid - 1;
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

int stringToInteger(string input) {
    return stoi(input);
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
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
