#include "AllInclude.h"
class Solution {
    public:
        ListNode* reverse(ListNode* cur)
        {
            ListNode* prev = NULL;
            while(cur)
            {

                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            return prev;
        }

        bool isPalindrome(ListNode* head) {
            if(!head || !head->next)
                return true;
            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* prev = NULL;
            while(fast && fast->next)
            {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }
            prev->next = NULL;
            fast = reverse(slow);
            slow = head;

            while(slow && fast && slow->val == fast->val)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return NULL == slow && (NULL == fast || NULL == fast->next);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
