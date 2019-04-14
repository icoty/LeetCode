#include "AllInclude.h"

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if(nums.size() < 2)
                return;
            int i = 0;  // i前面全是红色
            int j = 0;  // j扫描遍历
            int k = nums.size() - 1;    //  k后面全是蓝色
            while(j <= k){
                if(0 == nums[j]){
                    swap(nums[i], nums[j]);
                    ++i;
                    ++j;
                }else if(1 == nums[j]){
                    ++j;
                }else{
                    swap(nums[j], nums[k]);
                    --k;
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

        Solution().sortColors(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
