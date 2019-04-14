#include "AllInclude.h"

class Solution {
    public: // https://blog.csdn.net/huanghanqian/article/details/77141719
        int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
            if(1 == buckets)
                return 0;
            int row = (minutesToTest / minutesToDie) + 1;
            int total = row;
            int pig = 1;
            while(total < buckets){
                total *= row;
                ++pig;
            }
            return pig;
        }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int buckets = stringToInteger(line);
        getline(cin, line);
        int minutesToDie = stringToInteger(line);
        getline(cin, line);
        int minutesToTest = stringToInteger(line);

        int ret = Solution().poorPigs(buckets, minutesToDie, minutesToTest);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
