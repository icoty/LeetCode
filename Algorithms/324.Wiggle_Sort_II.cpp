#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/5139057.html ; O(n)时间 O(1)空间没看懂
        void wiggleSort(vector<int>& nums) {
            vector<int> tmp = nums;
            sort(tmp.begin(), tmp.end());
            int n = nums.size(); 
            int k = (n - 1) / 2;
            int j = n - 1;
            int i = 0;
            while(i < n){
                nums[i] = i++ & 1 ? tmp[j--] : tmp[k--];
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

        Solution().wiggleSort(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
