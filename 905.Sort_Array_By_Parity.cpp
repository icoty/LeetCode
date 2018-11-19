#include "AllInclude.h"

class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& A) {
            if(A.size() < 2)
                return A;
            int i = 0;
            int j = A.size() - 1;
            while(i < j)
            {
                while(i < j && 0 == A[i] % 2)
                    ++i;

                while(i < j && 1 == A[j] % 2)
                    --j;

                if(i < j)
                {
                    A[i] ^= A[j];
                    A[j] ^= A[i];
                    A[i] ^= A[j];
                    ++i;
                    --j;
                }     
            }
            return A;
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
        vector<int> A = stringToIntegerVector(line);

        vector<int> ret = Solution().sortArrayByParity(A);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
