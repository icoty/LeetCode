#include "AllInclude.h"

class Solution {
    public:
        bool isPalindrome(string s)
        {
            return s == string(s.rbegin(), s.rend());
        }

        void dfs(string s, int start, vector<string>& path)
        {
            if(s.size() == start)
                ret.push_back(path);

            for(int i = start; i < s.size(); ++i)
            {
                if(isPalindrome(s.substr(start, i - start + 1))){
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(s, i + 1, path);
                    path.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s) {
            vector<string> one;
            int start = 0;
            dfs(s, start, one);
            return ret;
        }

    private:
        vector<vector<string>> ret;
};
