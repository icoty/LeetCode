#include "AllInclude.h"

class Solution {
    public:
        int trap(vector<int>& h) {
            if(h.size() < 3)
                return 0;
            h.insert(h.begin(), 0);
            h.insert(h.end(), 0);

            int sum = 0;
            int l = 1;
            int r = h.size() - 2;
            while(l < r){
                if(h[l] < h[r]){
                    if(h[l] < h[l - 1]){
                        sum += h[l - 1] - h[l];
                        h[l] = h[l - 1];
                    }
                    ++l;
                }else{
                    if(h[r] < h[r + 1]){
                        sum += h[r + 1] - h[r];
                        h[r] = h[r + 1];
                    }
                    --r;
                }
            }

            if(l == r && min(h[l - 1], h[l + 1]) > h[l])
                sum += min(h[l - 1], h[l + 1]) - h[l];

            return sum;
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

        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
