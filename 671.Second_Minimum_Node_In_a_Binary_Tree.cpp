#include "AllInclude.h"


#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))

class Solution {
    public:
        int findSecondMinimumValue(TreeNode* root) {
            int ret = -1;
            search(root, ret);
            return ret;
        }

        void search(TreeNode* root, int& ret)
        {
            if(!root || !root->left || !root->right)
                return;
            if(root->left->val == root->right->val)
            {
                search(root->left, ret);
                search(root->right, ret);
            }else{
                int tmp = MAX(root->left->val, root->right->val);
                if(-1 == ret){
                    ret = tmp;
                }else{
                    ret = MIN(ret, tmp);
                }

                if(root->left->val < root->right->val) 
                    search(root->left, ret);
                else 
                    search(root->right, ret);
            }
        }
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

        int ret = Solution().findSecondMinimumValue(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
