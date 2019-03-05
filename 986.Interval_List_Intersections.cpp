#include "AllInclude.h"

class Solution {
    public:
        vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
            vector<Interval> ret;
            for(int i = 0, j = 0; i < A.size() && j < B.size();){
                if(A[i].end < B[j].start)
                    ++i;
                else if(B[j].end < A[i].start)
                    ++j;
                else if(A[i].end == B[j].start)
                {
                    ret.push_back(Interval(A[i].end, B[j].start));
                    ++i;
                }
                else if(B[j].end == A[i].start)
                {
                    ret.push_back(Interval(B[j].end, A[i].start));
                    ++j;
                }
                else if(A[i].start >= B[j].start && A[i].end <= B[j].end)
                {
                    ret.push_back(Interval(A[i].start, A[i].end));
                    ++i;
                }
                else if(A[i].start <= B[j].start && A[i].end >= B[j].end)
                {
                    ret.push_back(Interval(B[j].start, B[j].end));
                    ++j;
                }
                else if(A[i].start > B[j].start)
                {
                    ret.push_back(Interval(A[i].start, B[j].end));
                    ++j;
                }   
                else // if(A[i].start < B[j].start)
                {
                    ret.push_back(Interval(B[j].start, A[i].end));
                    ++i;
                }
            }

            return ret;
        }
};
