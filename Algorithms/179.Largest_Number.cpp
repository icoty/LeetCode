#include "AllInclude.h"

class myCmp{
    public:
        bool operator()(int l, int r){
            if(0 == l || 0 == r)
                return l > r;
            int ltmp = l;
            int rtmp = r;
            long long lcnt = 1;
            long long rcnt = 1;
            while(ltmp){
                ltmp /= 10;
                lcnt *= 10;
            }

            while(rtmp){
                rtmp /= 10;
                rcnt *= 10;
            }

            return l * rcnt + r > r * lcnt + l; // 举例l = 34 r = 89时, return 3489 > 8934
        }
}mycmp;

class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            string ret;
            sort(nums.begin(), nums.end(), mycmp);
            for(auto ele : nums){
                ret.append(to_string(ele));
            }
            return ret[0] == '0' ? "0" : ret;
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

        string ret = Solution().largestNumber(nums);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
