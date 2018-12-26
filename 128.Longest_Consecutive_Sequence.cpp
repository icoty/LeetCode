#include "AllInclude.h"

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> st;
            for(auto ele : nums)
                st.insert(ele);

            int ret = 0;
            for(auto ele : st){
                int l = 0;  // storage Consecutive count of left
                int r = 0;  // storage Consecutive count of right
                int i = 1;
                int j = 1;
                while(st.count(ele - i)){
                    st.erase(ele - i);
                    ++l;
                    ++i;
                }
                while(st.count(ele + j)){
                    st.erase(ele + j);
                    ++r;
                    ++j;
                }  
                ret = max(ret, l + r + 1);
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().longestConsecutive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
