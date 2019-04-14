#include "AllInclude.h"

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0; 
            int j = height.size() - 1;
            int ret = 0;
            while(i < j){
                int tmp = min(height[i], height[j]);
                ret = max(ret, (j - i) * tmp);
                while(i < j && height[i] == tmp)
                    ++i;
                while(i < j && height[j] == tmp)
                    --j;
            }
            return ret;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
