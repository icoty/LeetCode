#include "AllInclude.h"

class Solution {
    public:
#if 0
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

        int strStr(string haystack, string needle) {
            if(needle.empty()) 
                return 0;
            if(haystack.empty() || needle.size() > haystack.size())
                return -1;

            vector<int> next(needle.size() + 1);
            getNext(needle, next);

            int i = 0;
            int j = 0;
            int l1 = haystack.size();
            int l2 = needle.size();
            while(i < l1 && j < l2)
            {
                if(-1 == j || haystack[i] == needle[j])
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
                return i - l2;
            else
                return -1;
        }
#endif
        int repeatedStringMatch(string A, string B) {
            int m = A.size();
            int n = B.size();
            for(int i = 0; i < m; ++i)
            {   //  https://www.cnblogs.com/grandyang/p/7631434.html
                int j = 0;
                while(j < n && A[(i + j) % m] == B[j]){
                    ++j;
                }
                if(j == n)
                    return (i + j - 1) / m + 1;
            }
            return -1;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);

        int ret = Solution().repeatedStringMatch(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
