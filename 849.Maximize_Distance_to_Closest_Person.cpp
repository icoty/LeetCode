#include "AllInclude.h"

class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            int start = 0;  // 第一个1的下标
            int len = seats.size();
            while(start < len && 1 != seats[start])
                ++start;
            int dis = start;
            for(int i = start; i < len; ++i)
            {
                if(1 == seats[i])
                {
                    dis = max(dis, (i - start) / 2);
                    start = i;
                }
            }

            dis = max(dis, len - 1 - start);
            return dis;
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
        vector<int> seats = stringToIntegerVector(line);

        int ret = Solution().maxDistToClosest(seats);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
