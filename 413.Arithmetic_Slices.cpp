#include "AllInclude.h"

class Solution {
    public: // https://www.cnblogs.com/rgvb178/p/5967894.html
        int numberOfArithmeticSlices(vector<int>& A) {
            if(A.size() < 3)
                return 0;

            int cnt = 1;
            int ret = 0;
            for(int i = 1; i < A.size() - 1; ++i){
                if(A[i] - A[i-1] == A[i+1] - A[i])
                    ret += cnt++;
                else
                    cnt = 1;    
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().numberOfArithmeticSlices(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
