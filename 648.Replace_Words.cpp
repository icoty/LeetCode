#include "AllInclude.h"

class Solution {
public:
#if 0
    string replaceWords(vector<string>& dict, string s) {
        string ret;
        stringstream is(s);
        string word;
        while(is >> word){
            int minl = INT_MAX;
            for(auto & ele : dict){
                if(word.size() < ele.size())
                    continue;
                if(word.substr(0, ele.size()) == ele)
                    minl = min(minl, (int)ele.size());
            }
            ret += (minl == INT_MAX ? word : word.substr(0, minl)) + " ";
        }
        
        if(ret.back() == ' ')
            ret.pop_back();
        return ret;
    }
#else
typedef struct Trie_node   {
    bool exist; /// 标记该结点处是否构成单词
    struct Trie_node* next[26]; /// 指向各个子树的指针
    Trie_node() : exist(false) {
        memset(next, 0, sizeof(Trie_node*)*26);
    }
} TrieNode, *Trie;

    string replaceWords(vector<string>& dict, string sentence) {
        string res;
        if(sentence.length() == 0)
            return res;

        Trie root = new TrieNode();
        buildTrie(root, dict);

        stringstream ss(sentence);
        string temp;
        ss >> temp;
        res += findStr(root, temp);
        while(ss >> temp)
            res += " " + findStr(root, temp);
        return res;
    }

    void buildTrie(Trie root, const vector<string>& dict) {
        int index;
        for(int j=0; j<dict.size(); ++j) {
            Trie p = root;
            int i = 0;
            for(; i<dict[j].length(); ++i) {
                index = dict[j][i]-'a';
                if(p->next[index] == NULL)
                    p->next[index] = new TrieNode();
                p = p->next[index];
                if(i == dict[j].length()-1)
                    p->exist = true;
            }
        }
    }

    string findStr(Trie root, const string& str) {
        Trie p = root;
        int index;
        for(int i=0; i<str.length(); ++i) {
            index = str[i]-'a';
            if(p->next[index]) {
                if(p->next[index]->exist)
                    return str.substr(0, i+1);
                p = p->next[index];
            } else
                return str;
        }
        return str;
    }
#endif
};
