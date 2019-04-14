#include "AllInclude.h"

class Solution {
public:
    int numRabbits(vector<int>& an) {
        unordered_map<int, int> mp;
        for(auto & ele : an)
            ++mp[ele + 1];
        
        int ret = an.size();
        for(auto & ele : mp){
            if(ele.second % ele.first)
                ret += ele.first - (ele.second % ele.first);
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
        vector<int> answers = stringToIntegerVector(line);
        
        int ret = Solution().numRabbits(answers);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
