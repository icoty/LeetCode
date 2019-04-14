#include "Include.h"

class Solution {
public:
    int clumsy(int N){
        int ret = 0;
        bool posi = true;
        while(N){
            if(5 == N){
                ret += (posi ? 5 : -5) * 4 / 3 + 2 - 1;
                N -= 5;
            }else if(4 == N){
                ret += (posi ? 4 : -4) * 3 / 2 + 1;
                N -= 4;
            }else if(3 == N){
                ret += (posi ? 3 : -3) * 2 / 1;
                N -= 3;
            }else if(2 == N){
                ret += (posi ? 2 : -2) * 1;
                N -= 2;
            }else if(1 == N){
                ret += (posi ? 1 : -1);
                N -= 1;
            }else{
                ret += (posi ? N : -N) * (N - 1) / (N - 2) + N - 3;
                N -= 4;
                posi = false;
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
        int N = stringToInteger(line);
        
        int ret = Solution().clumsy(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
