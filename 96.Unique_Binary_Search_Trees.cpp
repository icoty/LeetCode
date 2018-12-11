#include "AllInclude.h"

class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for(int i = 1; i <= n; ++i){
                for(int j = 0; j < i; ++j){
                    dp[i] += dp[j] * dp[i - 1 - j]; // 共i节点时, 减去根节点, 还有i - 1个节点, 左子树从0 ~ i-1, 相应的右子树从i-1 ~ 0;
                }
            }
            return dp[n];
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
