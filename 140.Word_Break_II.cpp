#include "AllInclude.h"

#if 0
class Node{
    vector<Node*> child;
    string str;

    Node()
        :str("") 
    {
        child.resize(26, 0);
    }

    ~Node()
    {
        for(auto & ele : child)
            if(ele)
                delete ele;
    }   
};

class Trie{
    Node* root;

    Trie()
        :root(new Node())
    { }

    ~Trie()
    {
        if(root)
            delete root;
    }

    void insert(string & str)
    {
        Node* cur = root;
        for(auto & ele : str){
            if(!cur->child[ele - 'a'])
                cur->child[ele - 'a'] = new Node();
            cur = cur->child[ele - 'a'];
        }

        cur->str = str;
    }
}

class Solution {
    public:
        void dfs(string s, string one, vector<string>& words, Node* p, int i, vector<string> & ret)
        {
            if(p[s[i] - 'a']){
                Node* tmp = p;
                for(int j = i + 1; j < s.size(); ++j){
                    if(tmp->child[s[j] - 'a'] && tmp->child[s[j] - 'a'])
                        tmp = tmp->
                }
            }
            if(i == s.size() - 1 && !p->str.empty()){
                ret.push_back(one + " " + p->str);
                return;
            }

            for()
                if(p[s[i]] - 'a')
        }

        vector<string> wordBreak(string s, vector<string>& words) {
            vector<string> ret;
            if(s.empty() || words.empty())
                return ret;
            Trie T;
            for(auto & ele : words)
                T.insert(ele);
            dfs(s, "", words, T.root->child, 0, ret);
        }
};
#endif

class Solution {
    public:
        unordered_map<string, vector<string>> m;
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            if (m.count(s)) return m[s];
            if (s.empty()) return {""};
            vector<string> res;
            for (string word : wordDict) {
                if (s.substr(0, word.size()) != word) continue;
                vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
                for (string str : rem) {
                    res.push_back(word + (str.empty() ? "" : " ") + str);
                }
            }
            return m[s] = res;
        }
};
