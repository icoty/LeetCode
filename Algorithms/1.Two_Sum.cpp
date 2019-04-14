#include "AllInclude.h"

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ret;
            unordered_map<int,int> has;
            for(int i=0; i<nums.size();++i)
                has[nums[i]]=i;

            for(int i=0; i<nums.size(); ++i)
            {
                //int temp = target-nums[i];
                if(has.count(target-nums[i]) && has[target-nums[i]]!=i)
                {
                    ret.push_back(i);
                    ret.push_back(has[target-nums[i]]);
                    break;
                }   
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
    string aa = "ll";
    cout << " " << (-1 < aa.size());

    while (getline(cin, line)) {
        // delim = ','
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
