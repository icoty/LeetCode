#include "AllInclude.h"

class Solution {
    public: //  http://www.cnblogs.com/grandyang/p/6073317.html
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            int ret = 0;
            unordered_map<int, int> ab;
            for(auto ele : A)
                for(auto e : B)
                    ++ab[ele + e];

            for(auto ele : C)
                for(auto e : D)
                {
                    if(ab.count(0 - ele - e))
                        ret += ab[0 - ele - e];
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
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> C = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> D = stringToIntegerVector(line);

        int ret = Solution().fourSumCount(A, B, C, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
