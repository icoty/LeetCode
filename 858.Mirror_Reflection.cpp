#include "AllInclude.h"

class Solution {
public:  // https://blog.csdn.net/fuxuemingzhu/article/details/82432579
    int mirrorReflection(int p, int q) {
        int m = q, n = p;
        while(m % 2 == 0 && n % 2 == 0){
            m = m / 2;
            n = n / 2;
        }

        if(m % 2 == 0 && n % 2 == 1){
            return 0;
        }else if(m % 2 == 1 && n % 2 == 0){
            return 2;
        }else if(m % 2 == 1 && n % 2 == 1){
            return 1;
        }
        
        return -1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int p = stringToInteger(line);
        getline(cin, line);
        int q = stringToInteger(line);
        
        int ret = Solution().mirrorReflection(p, q);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}