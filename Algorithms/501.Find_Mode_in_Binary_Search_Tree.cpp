#include "AllInclude.h"

class Solution {
    public:
        vector<int> findMode(TreeNode* root) 
        {
            if(!root) 
                return {};
            vector<int> ret;
            TreeNode* pre = NULL;
            int max = 0;
            int count = 1;
            inorder(root, pre, max, count, ret);
            return ret;
        }

        void inorder(TreeNode* root, TreeNode*& pre, int& max, int& count, vector<int>& ret){
            if(!root) 
                return;
            inorder(root->left, pre, max, count, ret);
            if(NULL != pre) 
            {
                if(root->val == pre->val){
                    ++count;
                }else{
                    count = 1;
                }
            }
            if(count >= max) {
                if(count > max) {
                    ret.clear();
                }
                ret.push_back(root->val);
                max = count;
            }
            pre = root;
            inorder(root->right, pre, max, count, ret);
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        vector<int> ret = Solution().findMode(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
