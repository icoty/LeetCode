#include "AllInclude.h"

class Solution {
    public:
        TreeNode* create(vector<int>& preorder, int left1,int right1, vector<int>& inorder, int left2, int right2)
        {
            if(left1 > right1)
                return NULL;
            TreeNode* tmp = new TreeNode(preorder[left1]);

            int k;
            for(k = left2; k <= right2; ++k)
            {
                if(inorder[k] == preorder[left1]){
                    break;  //  (k - left2)左子树节点个数
                }
            }


            tmp->left = create(preorder, left1 + 1, left1 + (k - left2), inorder, left2, k - 1);
            tmp->right = create(preorder, left1 + 1 + (k - left2), right1, inorder, k + 1, right2);
            return tmp;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
            return create(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);

        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
