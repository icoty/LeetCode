#include "AllInclude.h"

#define SWAP(A, B) {(A) ^= (B); (B) ^= (A); (A) ^= (B);}

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int slow = 0;
            int fast = 0;
            int len = nums.size();
            while(slow <= len - 2 && fast <= len - 1)
            {
                while(0 != nums[slow])
                    ++slow;
                fast = slow;
                while(0 == nums[fast])
                    ++fast;
                if(fast <= len - 1)
                {
                    SWAP(nums[slow], nums[fast]);
                    ++slow;
                    ++fast;
                }
            }
            return;
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

        Solution().moveZeroes(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
