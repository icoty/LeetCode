class Solution {
    public:
        int numComponents(ListNode* head, vector<int>& G) {
            unordered_set<int> st;
            for(auto & ele : G){
                st.insert(ele);
            }

            int ret = 0;
            bool flg = false;
            while(head){
                if(st.count(head->val)){
                    flg = true;
                }else{
                    if(flg){
                        ++ret;
                        flg = false;
                    }
                }
                head = head->next;
            }
            return flg ? ret + 1 : ret;
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

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        vector<int> G = stringToIntegerVector(line);

        int ret = Solution().numComponents(head, G);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
