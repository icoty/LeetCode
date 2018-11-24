#include "AllInclude.h"
class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            set<string> st;
            for(auto ele: emails)
            {
                string one;
                bool plus = false;
                bool aita = false;
                for(auto ch: ele)
                {
                    if('@' == ch)
                    {
                        aita = true;
                        plus = false;
                    }
                    if(!aita && '+' == ch)
                        plus = true;
                    if(aita)
                        one.append(1, ch);
                    else
                        if(!plus && '.' != ch)
                            one.append(1, ch);
                }
                st.insert(one);
            }
            return st.size();
        }
};
