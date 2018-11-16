#include "AllInclude.h"

void trim(string &str)
{
    int i = 0;
    int j = str.length() - 1;
    for(; i < str.size() && str[i] == ' '; ++i);
    for(; j >= 0 && str[j] == ' '; --j);
    str = str.substr(i, j);
    cout << str << "---";
    int fir_sp = -1; 
    int fir_non_sp = -1; 
    for(int idx = 0; idx < str.size(); ++idx)
    {   
        if(str[idx] == ' ' && str[idx + 1] == ' ')
        {   
            fir_sp = idx;
            while(str[idx] == ' ')
                ++idx;
            fir_non_sp = idx;
            int l = fir_sp + 1, k = fir_non_sp;
            for(; str[k] != ' '; ++l, ++k)
            {   
                str[l] = str[k];
                str[k] = ' ';
            }   
            idx = l - 1;
        }    
    }   

    if(-1 != fir_sp)
        str = str.substr(0, fir_sp); 
}

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ret;
            unordered_map<int,int> has;
            for(int i=0; i<nums.size();++i)
                has[nums[i]]=i;

            for(int i=0; i<nums.size(); ++i)
            {
                //int temp = target-nums[i];
                if(has.count(target-nums[i]) && has[target-nums[i]]!=i)
                {
                    ret.push_back(i);
                    ret.push_back(has[target-nums[i]]);
                    break;
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
        cout << line << endl;
        line = line.substr(0, line.length()-2);
         trim(line);
        cout << line << endl;
    }
    return 0;
}
