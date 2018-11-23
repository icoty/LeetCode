#include "AllInclude.h"

class Solution {
    public:
        void getNext(string substr, vector<int> &next)
        {
            next[0] = -1;
            int j = -1;
            for(int i = 0; i < substr.size();)
            {
                if(-1 == j || substr[i] == substr[j])
                {
                    ++i;
                    ++j;
                    next[i] = j;
                }
                else
                    j = next[j];
            }
        }

        bool rotateString(string A, string B) {
            if(A.size() != B.size())
                return false;
            if(A == B)
                return true;
            A += A;

            vector<int> next(B.size() + 1);
            getNext(B, next);

            int i = 0;
            int j = 0;
            int l1 = A.size();
            int l2 = B.size();
            while(i < l1 && j < l2)
            {
                if(-1 == j || A[i] == B[j])
                {
                    ++i;
                    ++j;
                }
                else
                {
                    j = next[j];
                }
            }

            if(j == l2)
                return true; //return i - l2;
            else
                return false;


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

        bool ret = Solution().rotateString(A, B);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
