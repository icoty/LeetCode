#include "AllInclude.h"

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int m = nums.size();
            if(m < 2)
                return;
            int maxI = m - 1;

            for(int i = m - 2; i >= 0; --i){
                if(nums[i] > nums[maxI])
                    maxI = i;
                else if(nums[i] < nums[maxI]){
                    for(int j = i + 1; j < m; ++j){
                        if(nums[j] > nums[i])
                        {
                            if(min(nums[j], nums[maxI]) == nums[j])
                                maxI = j;
                        }
                    }

                    swap(nums[i], nums[maxI]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }

            sort(nums.begin(), nums.end());
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

        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
