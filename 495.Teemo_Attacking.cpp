#include "AllInclude.h"

class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int du) {
        if(ts.size() == 0)
            return 0;
        if(ts.size() == 1)
            return du;
        stack<int> st;
        st.push(ts[0] + du);
        int ret = du;
        for(int i = 1; i < ts.size(); ++i){
            if(ts[i] < st.top()){
                ret += ts[i] + du - st.top();
            }else{
                ret += du;
            }
            st.pop();
            st.push(ts[i] + du);
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> timeSeries = stringToIntegerVector(line);
        getline(cin, line);
        int duration = stringToInteger(line);
        
        int ret = Solution().findPoisonedDuration(timeSeries, duration);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}