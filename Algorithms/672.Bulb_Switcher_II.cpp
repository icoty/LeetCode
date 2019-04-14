#include "AllInclude.h"

class Solution {
public:
    int flipLights(int n, int m) {
        if(m == 0 || n == 0)
            return 1;
        else if(n == 1)
            return 2;
        else if(n == 2)
            return m == 1 ? 3 : 4;
        else
            return m == 1 ? 4 : (m == 2 ? 7 : 8);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int m = stringToInteger(line);
        
        int ret = Solution().flipLights(n, m);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
