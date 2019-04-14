#include "AllInclude.h"

class Solution {
    public: //  分数转小数,如果是优先循环小数,用()把循环体括起来
        string fractionToDecimal(int numerator, int denominator) {
            if (!numerator) return "0";
            string res;
            if (numerator < 0 ^ denominator < 0) res += '-';
            long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
            long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
            long integral = numer / denom;
            res += to_string(integral);
            long rmd = numer % denom;
            if (!rmd) return res;
            res += '.';
            rmd *= 10;
            unordered_map<long, long> mp; 
            while (rmd) {
                long quotient = rmd / denom;
                if (mp.find(rmd) != mp.end()) { 
                    res.insert(mp[rmd], 1, '(');
                    res += ')';
                    break;
                }
                mp[rmd] = res.size();   // 记录小数点所在位数的位置,当循环体出现时从对应位置插入(
                res += to_string(quotient);
                rmd = (rmd % denom) * 10;
            }
            return res;
        }        
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int numerator = stringToInteger(line);
        getline(cin, line);
        int denominator = stringToInteger(line);

        string ret = Solution().fractionToDecimal(numerator, denominator);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
