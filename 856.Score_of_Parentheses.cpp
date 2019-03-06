#include "AllInclude.h"

class Solution {
    public:
        int scoreOfParentheses(string S) {
            stack<int> st;
            for(int i = 0; i < S.size(); ++i){
                if(S[i] == '('){
                    st.push(0);
                }else if(S[i] == ')' && st.top() == 0){
                    st.pop();
                    int tmp = 1;
                    if(!st.empty() && st.top() != 0){
                        tmp += st.top();
                        st.pop();
                    }
                    st.push(tmp);
                }else{
                    int tmp = 2 * st.top();
                    st.pop();
                    st.pop();
                    if(!st.empty() && st.top() != 0){
                        tmp += st.top();
                        st.pop();
                    }
                    st.push(tmp);         
                }
            }

            return st.top();
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
        string S = stringToString(line);

        int ret = Solution().scoreOfParentheses(S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
