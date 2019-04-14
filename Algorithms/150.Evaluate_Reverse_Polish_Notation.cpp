#include "AllInclude.h"

/// 后缀表达式计算
class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<string> st;
            for(auto ele : tokens){
                if("+" == ele){
                    int another = stoi(st.top());
                    st.pop();
                    int one = stoi(st.top());
                    st.pop();
                    st.push(to_string(one + another));
                }else if("-" == ele){
                    int another = stoi(st.top());
                    st.pop();
                    int one = stoi(st.top());
                    st.pop();
                    st.push(to_string(one - another));              
                }else if("*" == ele){
                    int another = stoi(st.top());
                    st.pop();
                    int one = stoi(st.top());
                    st.pop();
                    st.push(to_string(one * another));              
                }else if("/" == ele){
                    int another = stoi(st.top());
                    st.pop();
                    int one = stoi(st.top());
                    st.pop();
                    st.push(to_string(one / another));              
                }else{
                    st.push(ele);
                }
            }
            return stoi(st.top());
        }
};
