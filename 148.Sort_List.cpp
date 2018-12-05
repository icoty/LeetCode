#include "AllInclude.h"

// https://www.cnblogs.com/grandyang/p/4249905.html
class Solution {
    public:
        ListNode* merge(ListNode* l1, ListNode* l2)
        {
            ListNode* r = new ListNode(-1);
            ListNode* cur = r;
            while(l1 && l2){
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }

            if(l1)
                cur->next = l1;
            if(l2)
                cur->next = l2;
            return r->next;
        }

        ListNode* sortList(ListNode* head) {
            if(!head || !head->next)
                return head;
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = head;
            while(fast && fast->next){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = NULL;

            return merge(sortList(head), sortList(slow));
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

        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
