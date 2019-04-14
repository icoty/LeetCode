#include "AllInclude.h"

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head || !head->next)
                return head;

            int count = 1;
            ListNode *slow = head;
            ListNode *fast = head;
            ListNode *prev = NULL;
            while(slow && slow->next)
            {
                ++count;
                prev = slow;
                slow = slow->next;
            }

            k = k % count;
            if(0 == k)
            {
                return head;
            }

            if(1 == k)
            {
                slow->next = head;
                prev->next = NULL;
                return slow;
            }

            slow = head;
            fast = head;
            prev = NULL;
            while(k > 1)
            {
                fast = fast->next;
                --k;
            }

            while(fast && fast->next)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }

            prev->next = NULL;
            fast->next = head;
            return slow;
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

ListNode* stringToListNode(string input) {
    vector<int> list = stringToIntegerVector(input);

    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        ListNode* ret = Solution().rotateRight(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
