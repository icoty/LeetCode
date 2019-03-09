#include "AllInclude.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* li1, ListNode* li2) {
        if(!li1)
            return li2;
        if(!li2)
            return li1;
        cout << "1";
        ListNode* l1 = reverse(li1);
        ListNode* l2 = reverse(li2);

        int carry = 0;
        ListNode *head = l1;
        ListNode *prevl1, *prevl2;
        while(l1 && l2)
        {
            int tmp = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1->val = tmp;
            prevl1 = l1;
            l1 = l1->next;
            prevl2 = l2;
            l2 = l2->next;
        }
        
        if(l2)
        {
            l1 = l2;
            prevl1->next = l1;
        }
        
        while(l1)
        {
            int tmp = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1->val = tmp;
            prevl1 = l1;
            l1 = l1->next;
        }

        if(carry)
        {
            ListNode* tail = new ListNode(carry);
            prevl1->next = tail;
        }
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* l){
        ListNode* head = NULL;
        while(l){
            ListNode* tmp = l->next;
            l->next = head;
            head = l;
            l = tmp;
        }
        return head;
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
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
