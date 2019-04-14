#include "AllInclude.h"

class Solution {
    public:
        void getLeaf(vector<int>& leaf, TreeNode* root)
        {
            if(!root)
                return;
            else if(!root->left && !root->right)
                leaf.push_back(root->val);
            else
            {
                getLeaf(leaf, root->left);
                getLeaf(leaf, root->right);
            }
            return;
        }

        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            if(!root1 || !root2)
                return false;
            vector<int> leaf1, leaf2;
            getLeaf(leaf1, root1);
            getLeaf(leaf2, root2);
            if(leaf1.size() != leaf2.size())
                return false;
            for(int i = 0; i < leaf1.size(); ++i)
                if(leaf1[i] != leaf2[i])
                    return false;
            return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root1 = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* root2 = stringToTreeNode(line);

        bool ret = Solution().leafSimilar(root1, root2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
