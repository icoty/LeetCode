#include "AllInclude.h"

class Solution {
    public:
        bool isMonotonic(vector<int>& A) {
            int len = A.size();
            if(A[len - 1] >= A[0]){
                return is_sorted(A.begin(),A.end());
            } else {
                return is_sorted(A.rbegin(),A.rend());
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);

        bool ret = Solution().isMonotonic(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
