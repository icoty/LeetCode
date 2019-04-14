#include "AllInclude.h"

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            long n1 = LONG_MIN;
            long n2 = LONG_MIN;
            long n3 = LONG_MIN;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] > n1){
                    n3 = n2;
                    n2 = n1;
                    n1 = nums[i];
                }
                if(nums[i] > n2 && nums[i] < n1){
                    n3 = n2;
                    n2 = nums[i];                
                }

                if(nums[i] >= n3 && nums[i] < n2){
                    n3 = nums[i];
                }
            }
            return n3 == LONG_MIN ? n1 : n3;
        }
#if 0
        int thirdMax(vector<int>& nums) {
            set<int> s;
            for(int n: nums){
                s.insert(n);
                if(s.size() > 3) s.erase(s.begin());
            }
            if(s.size() == 3) return *s.begin();
            return *(--s.end());
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
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().thirdMax(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
