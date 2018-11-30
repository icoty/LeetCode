#include "AllInclue.h"

class Solution {
    public:
        int dfs(TreeNode* root, int& sum)
        {
            int l = root->left ? dfs(root->left, sum) : 0;
            int r = root->right ? dfs(root->right, sum) : 0;
            int retl = root->left && root->left->val == root->val ? 1 + l : 0;
            int retr = root->right && root->right->val == root->val ? 1 + r : 0;
            sum = max(sum, retl + retr);
            return max(retl, retr);
        }

        int longestUnivaluePath(TreeNode* root) {
            int sum = 0;
            if(root)
                dfs(root, sum);
            return sum;
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

        int ret = Solution().longestUnivaluePath(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
