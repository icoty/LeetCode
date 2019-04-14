#include "AllInclude.h"

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string, vector<string>> tmp;
            for(int idx=0; idx < strs.size(); ++idx)
            {
                string temp = strs[idx];
                sort(temp.begin(), temp.end());
                tmp[temp].push_back(strs[idx]);
            }

            vector<vector<string>> ret;
            for(auto & ele: tmp)
            {
                ret.push_back(ele.second);
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

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(item.substr(1, input.length() - 1));
    }
    return output;
}

string stringVectorToString(vector<vector<string>> input) {
    if (input.size() == 0) {
        return "[]";
    }   

    string result;
    for(int idx = 0; idx < input.size(); ++idx)
    {
        string temp;
        for(int index = 0; index < input[idx].size(); index++) {
            temp += "\"" + input[idx][index] + ", ";
        } 
        temp = "[" + temp.substr(0, temp.length() - 2) + "]";
        result += temp + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<string> nums = stringToStringVector(line);

        vector<vector<string>> ret = Solution().groupAnagrams(nums);

        string out = stringVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
