#include "AllInclude.h"

class Solution {
    public:
        bool buddyStrings(string A, string B) {
            if(A.size() != B.size())
                return false;
            map<char, bool> dup;
            bool isdup = false;         
            vector<int> vec(200002, 0);
            int cnt = 0;                    // 对应位置不同字符的个数
            for(int i = 0; i < A.size(); ++i)
            {
                if(A[i] != B[i])
                    vec[cnt++] = i;
                if(!isdup)
                {
                    if(dup[A[i]])
                        isdup = true;       // 字符创中是否存在重复字符
                    else
                        dup[A[i]] = true;
                }
            }

            if(0 == cnt && isdup)
                return true;
            if(2 != cnt)
                return false;
            swap(A[vec[0]], A[vec[1]]);
            return A == B;
        }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);

        bool ret = Solution().buddyStrings(A, B);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
