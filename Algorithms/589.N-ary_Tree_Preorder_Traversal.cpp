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
        vector<int> preorder(Node* root) {
            vector<int> ret;
            if(!root)
                return ret;
            stack<Node*> s;
            s.push(root);
            while(!s.empty())
            {
                Node* tmp = s.top();
                ret.push_back(tmp->val);
                s.pop();
                for(int i = tmp->children.size() - 1; i >= 0; --i)
                {
                    s.push(tmp->children[i]);
                }
            }
            return ret;
        }
};
