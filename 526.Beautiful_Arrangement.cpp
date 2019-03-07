#include "AllInclude.h"

class Solution {
    public:
        void backtrack(int & N, vector<bool> & visit, int pos, int & ret){
            if(pos > N){
                ++ret;
                return;
            }

            for(int i = 1; i <= N; ++i){
                if(!visit[i] && (i % pos == 0 || pos % i == 0)){
                    visit[i] = true;
                    backtrack(N, visit, 1 + pos, ret);  // 1-N的每个位置都要符合规则
                    visit[i] = false;
                }
            }
        }

        int countArrangement(int N) {
            int ret = 0;
            vector<bool> visit(N+1, false);
            backtrack(N, visit, 1, ret);
            return ret;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().countArrangement(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}"
