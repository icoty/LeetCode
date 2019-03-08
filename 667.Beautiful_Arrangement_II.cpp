#include "AllInclude.h"

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        
        int l = 1, r = n;
        for(; ret.size() < k;){
            ret.push_back(l++);
            ret.push_back(r--);
        }
        
        if(k % 2){
            ++r;
            ret.pop_back();
            while(l <= r)
                ret.push_back(l++);
        }else{
            while(l <= r)
                ret.push_back(r--);
        }
        
        return ret;
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
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().constructArray(n, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}