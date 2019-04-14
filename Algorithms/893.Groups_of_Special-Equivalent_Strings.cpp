#include "AllInclude.h"

class Solution {
    public:
        int numSpecialEquivGroups(vector<string>& A) {
            set<string> fingerprint;
            for(auto ele: A)
            {
                string odd = "";
                string even = "";
                for(int i = 0; i < ele.size(); ++i)
                {
                    if(0 == i % 2)
                        even.append(1, ele[i]);
                    else
                        odd.append(1, ele[i]);
                }
                sort(odd.begin(), odd.end());
                sort(even.begin(), even.end());
                fingerprint.insert(odd + even);
            }
            return fingerprint.size();
        }
};
