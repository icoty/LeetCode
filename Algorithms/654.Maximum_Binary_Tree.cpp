#include "AllInclude.h"

class Solution {
    public:
        int maxPos(vector<int>& nums, int l, int r){
            int maxI = l;
            for(int i = l; i <= r; ++i){
                if(nums[i] > nums[maxI])
                    maxI = i;
            }

            return maxI;
        }

        TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r) {
            int maxI = maxPos(nums, l, r);
            TreeNode* root = new TreeNode(nums[maxI]);

            if(maxI > l)
                root->left = constructMaximumBinaryTree(nums, l, maxI - 1);
            if(maxI < r)
                root->right = constructMaximumBinaryTree(nums, maxI + 1, r);
            return root;
        }

        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return nums.empty() ? NULL : constructMaximumBinaryTree(nums, 0, nums.size() - 1);
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
        vector<int> nums = stringToIntegerVector(line);

        TreeNode* ret = Solution().constructMaximumBinaryTree(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
