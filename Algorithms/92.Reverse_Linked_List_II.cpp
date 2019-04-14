#include "AllInclude.h"

class Solution {
    public:
        ListNode* reverseList(ListNode* head)
        {
            ListNode* cur = head;
            ListNode* prev = NULL;
            while(cur)
            {
                ListNode* tmp = cur->next;
                head = cur;
                head->next = prev;
                prev = head;
                cur = tmp;
            }

            return head;
        }

        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if(!head || !head->next || m == n || 1 == n)
                return head;

            int pos = 1;
            ListNode* cur = head;
            ListNode* prevm = NULL;
            ListNode* prev = NULL;
            ListNode *nodem, *tailn;
            while(cur && cur->next)
            {
                ++pos;
                prev = cur;
                cur = cur->next;
                if(m == pos)
                {
                    prevm = prev;
                    prevm->next = NULL;
                    nodem = cur;
                }
                if(n == pos)
                {
                    tailn = cur->next;
                    cur->next = NULL;
                    break;
                }
            }

            ListNode* reverse = reverseList(nodem);
            cur = reverse;
            while(cur && cur->next)
                cur = cur->next;

            prevm->next = reverse;
            cur->next = tailn;
            return head;
        }
};


int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        ListNode* ret = Solution().reverseBetween(head, m, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
