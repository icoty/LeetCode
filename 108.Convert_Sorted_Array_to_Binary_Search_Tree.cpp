#include "AllInclude.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
#if 0
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if(0 == nums.size())
                return NULL;
            if(1 == nums.size())
            {
                TreeNode* node = new TreeNode(nums[0]);
                return node;
            }

            int mid = nums.size() / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            vector<int> vl(nums.begin(), nums.begin() + mid);
            vector<int> vr(nums.begin() + mid + 1, nums.end());
            root->left = sortedArrayToBST(vl);
            root->right = sortedArrayToBST(vr);

            return root;
        }
#else
        TreeNode* convert(vector<int>& nums, int l, int r){
            if(l > r)
                return NULL;
            else
            {
                int mid = (l + r) /2;
                TreeNode* tmp = new TreeNode(nums[mid]);
                tmp->left = convert(nums, l, mid - 1);
                tmp->right = convert(nums, mid + 1, r);
                return tmp;   
            }
        }

        TreeNode* sortedArrayToBST(vector<int>& nums){
            if(0 == nums.size())
                return NULL;
            else
            {
                return convert(nums, 0, nums.size() - 1);
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

        TreeNode* ret = Solution().sortedArrayToBST(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
