#include "AllInclude.h"

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) { 
        vector<int> v(4, 0);    
        v[1] = (A[0] != B[0] ? 1 : 0); // A中全是A[0]移动次数为v[0]  A中全是B[0]移动次数为v[1]
        v[3] = (A[0] != B[0] ? 1 : 0); // B中全是B[0]移动次数为v[2]  B中全是A[0]移动次数为v[3]
        
        for(int i = 1; i < A.size(); ++i){
            if(v[0] == -1 && v[1] == -1 && v[2] == -1 && v[3] == -1)
                return -1;
            if(A[i] != A[0] && B[i] != A[0])
                v[0] = -1;
            if(A[i] != B[0] && B[i] != B[0])
                v[1] = -1;
            if(B[i] != B[0] && A[i] != B[0])
                v[2] = -1;
            if(B[i] != A[0] && A[i] != A[0])
                v[3] = -1;
            
            if(v[0] != -1 && A[i] != A[0] && B[i] == A[0])
                v[0] += 1;
            if(v[1] != -1 && A[i] != B[0] && B[i] == B[0])
                v[1] += 1;
            if(v[2] != -1 && B[i] != B[0] && A[i] == B[0])
                v[2] += 1;
            if(v[3] != -1 && B[i] != A[0] && A[i] == A[0])
                v[3] += 1;
        }
        sort(v.begin(), v.end());
        
        if(v[2] == -1)
            return v[3];
        else if(v[1] == -1)
            return v[2];
        else if(v[0] == -1)
            return v[1];
        else
            return v[0];
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        
        int ret = Solution().minDominoRotations(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
