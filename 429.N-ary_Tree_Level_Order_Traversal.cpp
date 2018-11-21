#include "AllInclude.h"

class Node {
    public:
        int val = NULL;
        vector<Node*> children;

        Node() {}

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};

class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> ret;
            if(!root)
                return ret;
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                vector<int> vtmp;
                int len = q.size();
                for(int i = 0; i < len; ++i)
                {
                    Node* tmp = q.front();
                    q.pop();
                    vtmp.push_back(tmp->val);
                    for(int j = 0; j < tmp->children.size(); ++j)
                    {
                        if(tmp->children[j])
                            q.push(tmp->children[j]);
                    } 
                }
                ret.push_back(move(vtmp));
            }
            return ret;
        }
};
