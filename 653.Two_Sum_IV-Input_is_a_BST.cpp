#include "AllInclude.h"

class Solution {
    public:
        void inOrder(TreeNode* root, vector<int>& vec)
        {
            if(!root)
                return;
            inOrder(root->left, vec);
            vec.push_back(root->val);
            inOrder(root->right, vec);     
        }

        bool find(vector<int>& vec, int sum)
        {
            for(int i = 0, j = vec.size() - 1; i < j;)
            {
                if(vec[i] == sum - vec[j])
                    return true;
                else if(vec[i] > sum - vec[j])
                    --j;
                else
                    ++i;
            }
            return false;
        }

        bool findTarget(TreeNode* root, int k) {
            if(!root)
                return false;
            vector<int> ret;
            inOrder(root, ret);
            return find(ret, k);
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().findTarget(root, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
