#include "AllInclude.h"

class Codec {
public:
string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();        
}

TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);        
}

private:
void serialize(TreeNode* root, ostringstream& out) {
    if (root) {
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    } else {
        out << "# ";
    }
}

TreeNode* deserialize(istringstream& in) {
    string val;
    in >> val;
    if (val == "#")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
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

        string ret = Solution().Codec(root);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
