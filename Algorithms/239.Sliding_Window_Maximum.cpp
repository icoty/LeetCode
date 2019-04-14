#include "AllInclude.h"

class Solution {
    public:
#if 0
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            if(0 == nums.size())
                return {};
            if(1 == k)
                return nums;

            map<int, int> mp;
            int i = 0;
            for(; i < k; ++i)
                ++mp[nums[i]];        

            vector<int> ret;        
            ret.push_back(mp.rbegin()->first);  // map is sort by it's key, so mp.rbegin()->first must be the max of Sliding Window of size k

            while(i < nums.size()){
                ++mp[nums[i]];
                if(--mp[nums[i - k]] <= 0)
                    mp.erase(nums[i - k]);
                ret.push_back(mp.rbegin()->first);
                ++i;
            }

            return ret;
        }
#else
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ret;
            deque<int> q;
            for(int i = 0; i < nums.size(); ++i){
                if(!q.empty() && i - k == q.front())
                    q.pop_front();

                while(!q.empty() && nums[q.back()] < nums[i])
                    q.pop_back();
                q.push_back(i);
                if(i - k + 1 >= 0)  //Slid Window index range from i-k+1 to i
                    ret.push_back(nums[q.front()]);
            }

            return ret;
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        vector<int> ret = Solution().maxSlidingWindow(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
