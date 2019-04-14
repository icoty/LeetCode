#include "AllInclude.h"

class Solution {
    public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            stack<int> st;
            for(int i = 0, j = 0; i < pushed.size(); ++i){
                if(popped[j] == pushed[i]){
                    ++j;
                }else{
                    st.push(pushed[i]);
                }

                while(!st.empty() && st.top() == popped[j]){
                    st.pop();
                    ++j;
                }                
            }

            return st.empty();
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> pushed = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> popped = stringToIntegerVector(line);

        bool ret = Solution().validateStackSequences(pushed, popped);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
