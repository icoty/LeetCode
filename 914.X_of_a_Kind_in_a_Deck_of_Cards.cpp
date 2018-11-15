#include "AllInclude.h"

#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)

class Solution {
    public:
        bool hasGroupsSizeX(vector<int>& deck) {
            if(deck.size() <=1)
                return false;

            map<int, int> temp;
            for(int idx=0; idx < deck.size(); ++idx)
                ++temp[deck[idx]];

            int gcd = temp.begin()->second;
            for(auto &ele: temp)
            {
                int min = MIN(gcd, ele.second);
                int max = MAX(gcd, ele.second);
                int mod = max % min;
                while(mod)
                {
                    max = min;
                    min = mod;
                    mod = max % min;
                }

                gcd = min;
            }

            return gcd > 1;
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
    //input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> deck = stringToIntegerVector(line);

        bool ret = Solution().hasGroupsSizeX(deck);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
