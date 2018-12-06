#include "AllInclude.h"

class Solution {
    public:
        int calculate(string s) {
            stack<int> st;
            int ret = 0;
            int num = 0;
            char op = '+';  // 23 * 12 + 34 首先23入栈,然后op改为*,然后12给num,到+时计算23 * 12入栈
            for(int i = 0; i < s.size(); ++i){
                if(s[i] >= '0')
                    num = num * 10 + s[i] - '0';    // 处理形如 345 + 456 / 233中的数字

                if((s[i] < '0' && s[i] != ' ') || i == s.size() - 1){
                    if('+' == op)
                        st.push(num);
                    if('-' == op)
                        st.push(-1 * num);
                    if('*' == op || '/' == op)
                    {
                        int tmp = '*' == op ? st.top() * num : st.top() / num;
                        st.pop();
                        st.push(tmp);
                    }             
                    num = 0;
                    op = s[i];
                }
            }
            while(!st.empty()){
                ret += st.top();
                st.pop();
            }
            return ret;
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
        string s = stringToString(line);

        int ret = Solution().calculate(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
