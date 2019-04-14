#include "AllInclude.h"

class Solution {
    public:
#if 0
        int recur(int x, int y, int& m, int& n)
        {
            if(x == m || y ==n)
                return 1;
            return recur(x + 1, y, m, n) + recur(x, y + 1, m, n);
        }

        int uniquePaths(int m, int n) {
            if(0 == m || 0 == n)
                return 0;
            int r = m - 1;
            int c = n - 1;
            return recur(0, 0, r, c);
        }
#else
        int uniquePaths(int m, int n) {
            if(0 == m || 0 == n)
                return 0;
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for(int i = 0; i < m; ++i)
                dp[i][n - 1] = 1;
            for(int i = 0; i < n; ++i)
                dp[m - 1][i] = 1;
            for(int i = m - 2; i >= 0; --i)
            {
                for(int j = n - 2; j >= 0; --j)
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }

            return dp[0][0];
        }   
#endif
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
