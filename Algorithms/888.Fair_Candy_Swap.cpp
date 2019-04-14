#include "AllInclude.h"

/*
 *     1.设应交换的两个为A[i],B[j],则有 sumA - A[i] + B[j] = average;遍历每一个A[i], 判断B[j] = average - sumA + A[i]是否存在即可
 */
class Solution {
    public:
        vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
            vector<int> ret;
            multiset<int> bmp;
            int suma = 0;
            int sumb = 0;
            for(auto ele: A)
                suma += ele;
            for(auto ele: B)
            {
                sumb += ele;
                bmp.insert(ele);
            }
            int average = (suma + sumb) / 2;

            for(auto ele: A)
            {
                if(bmp.count(average - suma + ele))
                {
                    ret.push_back(ele);
                    ret.push_back(average - suma + ele);
                    break;
                }
            }
            return ret;
        }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);

        vector<int> ret = Solution().fairCandySwap(A, B);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
