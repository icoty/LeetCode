#include "AllInclude.h"

class Solution {
    public:
        vector<int> constructRectangle(int area) {
            vector<int> ret;
            int wid = sqrt(area);
            int len = sqrt(area);
            if(wid * len == area)
            {
                ret.push_back(wid);
                ret.push_back(len);
            }else{
                while(wid * len != area){
                    if(wid * len > area)
                        --len;
                    else
                        ++wid;
                }
                ret.push_back(wid);
                ret.push_back(len);            
            }
            return ret;
        }
};

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
        int area = stringToInteger(line);

        vector<int> ret = Solution().constructRectangle(area);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
