#include "AllInclude.h"

class Solution {
    public:
        int binarySearch(vector<int>& numbers, int left, int right, int key)
        {
            int mid;
            while(left <= right)
            {
                mid = (left + right) / 2;
                if(key == numbers[mid])
                    return mid;
                else if(key < numbers[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            return -1;
        }

        vector<int> twoSum(vector<int>& numbers, int target) {
            for(int i = 0; i < numbers.size(); ++i)
            {
                int index = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
                if(index > 0)
                    return {i+1, index + 1}; 
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
        vector<int> numbers = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(numbers, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
