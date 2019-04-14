#include "AllInclude.h"

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))

class Solution {
    public:
        int smallestRangeI(vector<int>& A, int K) {
            int min = 10000;
            int max = 0;
            for(auto ele: A)
            {
                max = MAX(max, ele);
                min = MIN(min, ele);
            }

            if(min + K >= max -K)
                return 0;
            return max - 2*K - min;  
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);

        int ret = Solution().smallestRangeI(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
