#include "AllInclude.h"

class Solution {
    public:
        Solution()
        {
            vec.resize(1 << 10);
            memset(vec.data(), 0, vec.size() * sizeof(int));
        }

        int climbStairs(int n) {
            if(1 == n || 2 == n)
                vec[n] = n;
            else
                if(0 == vec[n]) 
                    vec[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return vec[n];
        }

    private:
        vector<int> vec;
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
