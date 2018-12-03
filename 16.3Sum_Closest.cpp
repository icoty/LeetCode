#include "AllInclude.h"

class Solution {
    public: // http://www.cnblogs.com/grandyang/p/4510984.html
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(),nums.end());
            if(nums.size() < 3)
                return 0;
            int n = nums.size();
            int diff = abs(nums[0] + nums[1] + nums[2] - target);
            int ret = nums[0] + nums[1] + nums[2];
            for(int k = 0; k < n - 2; ++k)
            {
                if(k > 0 && nums[k] == nums[k - 1])
                    continue;
                int i =  k + 1;
                int j = n - 1;
                while(i < j)
                {
                    if(abs(target - nums[k] - nums[j] - nums[i]) < diff)
                    {
                        diff = abs(target - nums[k] - nums[j] - nums[i]);
                        ret = nums[k] + nums[j] + nums[i];
                    }

                    if(nums[k] + nums[j] + nums[i] < target)
                        ++i;
                    else
                        --j;
                }
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
