#include "AllInclude.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre, int start, int end) {
        if(start >= end)
            return NULL;
        TreeNode* root = new TreeNode(pre[start]);
        int rpos = start;
        while(rpos < pre.size() && pre[rpos] <= pre[start])
            ++rpos;
        root->left = bstFromPreorder(pre, start + 1, rpos);
        root->right = bstFromPreorder(pre, rpos, end);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return bstFromPreorder(pre, 0, pre.size());
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().bstFromPreorder(preorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
