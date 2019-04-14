#include "AllInclude.h"

class Solution {
public:
    string intToRoman(int num) {
        vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> str{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ret;
        for(int i = 0; i < val.size(); ++i){
            while(num >= val[i]){
                ret += str[i];
                num -= val[i];
            }
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
