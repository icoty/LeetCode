#include "AllInclude.h"

class RLEIterator {
public:
    RLEIterator(vector<int> A)
    :num(A)
    {
    }
    
    int next(int n) {
        while(n && !num.empty()){
            if(n <= num[0]){
                num[0] -= n;
                return num[1];
            }else{
                n -= num[0];
                num.erase(num.begin());
                num.erase(num.begin());
                return next(n);
            }
        }
        return -1;
    }
private:
    vector<int> num;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
