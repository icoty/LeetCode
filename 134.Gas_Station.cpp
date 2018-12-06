#include "AllInclude.h"

class Solution {
    public:
        bool dfs(vector<int>& gas, vector<int>& cost, int start, int cur, int& sum)
        {
            int m = gas.size();
            if(cur == start + m)
                return true;
            if(gas[cur % m] + sum < cost[cur % m])
                return false;
            sum += gas[cur % m];
            sum -= cost[cur % m];
            bool next = dfs(gas, cost, start, cur + 1, sum);
            sum -= gas[cur % m];
            sum += cost[cur % m];
            return next;
        }

        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            if(gas.size() < 1)
                return 0;
            int r = gas.size();
            int sum = 0;
            for(int i = 0; i < r; ++i)
            {
                if(dfs(gas, cost, i, i, sum))
                    return i;
            }
            return -1;
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
        vector<int> gas = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> cost = stringToIntegerVector(line);

        int ret = Solution().canCompleteCircuit(gas, cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
