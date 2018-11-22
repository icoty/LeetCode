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
        int recursev(Node* cur, int& dep)
        {
            if(!cur)
                return 0;
            int max = 0;
            for(int i = 0; i < cur->children.size(); ++i)
            {
                int one = recursev(cur->children[i], dep);
                if(max < one)
                    max = one;  
            }
            dep = max + 1;
            return 1 + max;
        }

        int maxDepth(Node* root) {
            int dep = 0;
            recursev(root, dep);
            return dep;
        }
};
