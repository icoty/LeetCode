#include "AllInclude.h"

class Solution {
    public:
#if 0   
        vector<int> countSmaller(vector<int>& nums) {
            map<int, set<int>> mp;
            vector<int> ret(nums.size(), 0);
            for(int i = 0; i < (int)nums.size(); ++i)
                mp[nums[i]].insert(i);

            for(int i = 0; i < (int)nums.size(); ++i){
                for(auto &ele : mp){
                    if(ele.first == nums[i]){
                        if(1 == (int)ele.second.size())
                            mp.erase(nums[i]);
                        else
                            ele.second.erase(i);
                        break;
                    }else{
                        ret[i] += ele.second.size();
                    }
                }
            }
            return ret;
        }
#else
        vector<int> countSmaller(vector<int>& nums) {
            std::vector<int> res;

            for(size_t i = 0; i < nums.size(); i++)
            {
                int counter = 0;
                for(size_t j = i+1; j < nums.size(); j++)
                {
                    if(nums[j] < nums[i])
                    {
                        counter++;
                    }
                }

                res.push_back(counter);
            }
            return res;
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

        vector<int> ret = Solution().countSmaller(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
