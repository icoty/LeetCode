#include "AllInclude.h"

class Solution {
public:
    int getDays(vector<int>& w, int mid, int D){
        int total = 0;
        int cnt = 0;
        for(int i = 0; i < w.size(); ++i){
            total += w[i];
            if(total > mid){
                total = w[i];
                ++cnt;
            }
        }
        return cnt;
    }
    
    int binarySearch(vector<int>& w, int l, int r, int& D){
        int mid = 0;
        while(l < r){
            mid = l + (r - l) / 2;
            if(getDays(w, mid, D) < D){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    
    int shipWithinDays(vector<int>& w, int D) {
        int maxV = 0;
        int sum = 0;
        for(int i = 0; i < w.size(); ++i){
            sum += w[i];
            maxV = max(w[i], maxV);
        }
        
        return binarySearch(w, maxV, sum, D);
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> weights = stringToIntegerVector(line);
        getline(cin, line);
        int D = stringToInteger(line);
        
        int ret = Solution().shipWithinDays(weights, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
