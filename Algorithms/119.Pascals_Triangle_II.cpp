#include "AllInclude.h"

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            if(rowIndex < 0)
            {
                vector<int> ret;
                return ret;
            }else if(0 == rowIndex)
            {
                vector<int> ret(1, 1);
                return ret;            
            }else if(1 == rowIndex)
            {
                vector<int> ret(2, 1);
                return ret;
            }
            else
            {
                vector<int> ret = getRow(rowIndex - 1);
                ret.push_back(1);
                int prev = ret[0];
                for(int i = 1, j = ret.size() - 2; i <= j; ++i, --j)
                {
                    int tmp = ret[i];
                    ret[i] += prev;
                    ret[j] = ret[i];
                    prev = tmp;
                }
                return ret; 
            }
        }
};

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
        int rowIndex = stringToInteger(line);

        vector<int> ret = Solution().getRow(rowIndex);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
