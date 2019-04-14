#include "AllInclude.h"

class Solution {
    public:
        bool validMountainArray(vector<int>& A) {
            if(A.size() < 3)
                return false;
            int i = 0;
            int j = A.size() - 1;
            while(i < A.size() - 1 && A[i] < A[1 + i])
                ++i;
            if(A.size() - 1 == i)
                return false;

            while(j > 0 && A[j] < A[j - 1])
                --j;

            return i == j && j != 0;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);

        bool ret = Solution().validMountainArray(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
