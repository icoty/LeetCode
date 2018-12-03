#include "AllInclude.h"

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            if(nums.size() < k)
                return 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            for(auto ele : nums)
            {
                if(pq.size() < k)
                    pq.push(ele);
                else if(ele > pq.top())
                {
                    pq.pop();
                    pq.push(ele);
                }
            }
            return pq.top();
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
        int k = stringToInteger(line);

        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
