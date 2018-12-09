#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/5928417.html
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b){    return a.first > b.first ||(a.first == b.first && a.second < b.second); });

            for(int i = 1; i < people.size(); ++i)
            {
                int cnt = 0;
                for(int j = 0; j < i; ++j)
                {
                    if(cnt == people[i].second)
                    {
                        pair<int, int> tmp = people[i];
                        for(int k = i - 1; k >= j; --k)
                        {
                            people[k + 1] = people[k];
                        }
                        people[j] = tmp;
                        break;
                    }

                    if(people[j].first >= people[i].first)
                        ++cnt;
                }
            }
            return people;
        }
};
