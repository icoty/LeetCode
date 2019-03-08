#include "AllInclude.h"

class Solution {
public: // https://leetcode.com/problems/beautiful-array/discuss/186679/C%2B%2BJavaPython-Odd-%2B-Even-Pattern-O(N)
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            for (int i : res) 
                if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
            for (int i : res) 
                if (i * 2 <= N) tmp.push_back(i * 2);
            res = tmp;
        }
        return res;
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
        int N = stringToInteger(line);
        
        vector<int> ret = Solution().beautifulArray(N);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}