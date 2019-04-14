#include "AllInclude.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MIN(A,B) ((A)<(B)?(A):(B))

class Solution {
    public:
#if 1
        int minDepth(TreeNode* root) {
            if(!root) 
                return 0;
            queue<TreeNode*> Q;
            Q.push(root);
            int i = 0;
            while(!Q.empty()) {
                i++;
                int k = Q.size();
                for(int j = 0; j < k; ++j) {
                    TreeNode* rt = Q.front();
                    if(rt->left) Q.push(rt->left);
                    if(rt->right) Q.push(rt->right);
                    Q.pop();
                    if(!rt->left && !rt->right) 
                        return i;
                }
            }
            return -1;
        }
#else    
        int minDepth(TreeNode* root) {
            if(!root)
                return 0;
            else
            {
                if(!root->left)
                    return 1 + minDepth(root->right);
                else if(!root->right)
                    return 1 + minDepth(root->left);
                else
                    return 1 + MIN(minDepth(root->left), minDepth(root->right));
            }
        }
#endif
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        int ret = Solution().minDepth(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
