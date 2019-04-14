#include "AllInclude.h"

class MedianFinder {
    public:
        /** initialize your data structure here. */
        MedianFinder() {

        }

        void addNum(int num) {
            if(0 == vec.size())
            {
                vec.push_back(num);
                return;
            }

            int l = 0;
            int r = vec.size() - 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(vec[mid] == num){
                    vec.insert(vec.begin() + mid, num);
                    return;
                }else if(vec[mid] < num){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }

            if(vec[l] < num)
                vec.insert(vec.begin() + l + 1, num);
            else
                vec.insert(vec.begin() + l, num);
        }

        double findMedian() {
            int m = vec.size();
            return 0 != m % 2 ? vec[m / 2] : double(vec[m / 2] + vec[(m - 1) / 2]) / 2;
        }

    private:
        vector<int> vec;
};

/**
 *  * Your MedianFinder object will be instantiated and called as such:
 *   * MedianFinder obj = new MedianFinder();
 *    * obj.addNum(num);
 *     * double param_2 = obj.findMedian();
 *      */
