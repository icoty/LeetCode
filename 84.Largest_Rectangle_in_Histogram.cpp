#include "AllInclude.h"

class Solution {
    public:
#if 0   
        int largestRectangleArea(vector<int>& heights) {
            int ret = 0;
            for(int i = 0; i < heights.size(); ++i){
                if(i + 1 < heights.size() && heights[i] <= heights[i + 1])
                    continue;
                int minh = heights[i];
                for(int j = i; j >= 0; --j){
                    minh = min(minh, heights[j]);
                    ret = max(ret, minh * (i - j + 1));
                }
            }
            return ret;
        }
#else
        int largestRectangleArea(vector<int>& heights) {
            int res = 0;
            stack<int> st;
            heights.push_back(0);   // aim to handle the last num of heights in line 23
            for(int i = 0; i < heights.size(); ++i) {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    int cur = st.top(); 
                    st.pop();       // st.top() = i-2 after the line
                    res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1))); 
                }
                st.push(i);
            }
            return res;
        }
#endif
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> heights = stringToIntegerVector(line);

        int ret = Solution().largestRectangleArea(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
