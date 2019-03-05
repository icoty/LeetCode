#include "AllInclude.h"

class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& pre, int prestart, int preend, vector<int>& post, int poststart, int postend) {
            if(prestart > preend || poststart > postend)
                return NULL;

            int leftcount = 0;
            for(int i = poststart; i <= postend - 1; ++i){
                ++leftcount;
                if(post[i] == pre[prestart + 1])
                    break;
            }

            TreeNode* node = new TreeNode(pre[prestart]);
            node->left = constructFromPrePost(pre, prestart + 1, prestart + leftcount, post, poststart, poststart + leftcount - 1);
            node->right = constructFromPrePost(pre, prestart + leftcount + 1, preend, post, poststart + leftcount, postend - 1);

            return node;
        }

        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
            return constructFromPrePost(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
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
        vector<int> pre = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> post = stringToIntegerVector(line);

        TreeNode* ret = Solution().constructFromPrePost(pre, post);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
