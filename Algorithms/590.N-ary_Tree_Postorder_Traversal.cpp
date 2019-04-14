#include "AllInclude.h"

class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};
class Solution {
    public:
#if 0
        vector<int> postorder(Node* root) {
            vector<int> ret;
            if(!root)
                return ret;
            stack<Node*> s;
            s.push(root);
            while(!s.empty())
            {
                Node* tmp = s.top();
                if(!tmp->children.size())
                    ret.push_back(tmp->val);
                else
                {
                    for(int i = tmp->children.size() - 1; i >= 0; --i)
                    {
                        s.push(tmp->children[i]);
                    }  
                }
            }
            return ret;
        }
#else
        void iteratively(Node* cur, vector<int>& ret)
        {
            for(auto ele: cur->children)
                iteratively(ele, ret); 
            ret.push_back(cur->val);  
        }

        vector<int> postorder(Node* root) {
            vector<int> ret;
            if(!root)
                return {};
            iteratively(root, ret);    
            return ret;
        } 
#endif
};
