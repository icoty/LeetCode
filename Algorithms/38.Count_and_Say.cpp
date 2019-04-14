#include "AllInclude.h"

class Solution {
    public:
        string countAndSay(int n) {
            if(1 == n){
                return "1";
            }else{
                string out = countAndSay(n - 1);
                string ret;
                int cnt = 1;
                int i = 0;
                for(; i < out.size() - 1; ++i){
                    if(out[i] == out[i+1])
                        ++cnt;
                    else
                    {
                        ret += to_string(cnt).append(1, out[i]);
                        cnt = 1;
                    }
                }
                ret += to_string(cnt).append(1, out[i]);
                return ret;
            }
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
