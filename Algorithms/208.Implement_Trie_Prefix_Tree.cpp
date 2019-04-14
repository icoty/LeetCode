#include "AllInclude.h"

class TrieNode{
    public:
        TrieNode* next[26] = {NULL};
        bool isLeaf;

        TrieNode()
            :isLeaf(false)
        {}
};

class Trie {
    public:
        /** Initialize your data structure here. */
        Trie()
        {
            root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode* cur = root;
            for(auto ele : word){
                if(!cur->next[ele - 'a'])
                    cur->next[ele - 'a'] = new TrieNode();
                cur = cur->next[ele - 'a'];
            }
            cur->isLeaf = true;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode* cur = root;
            for(auto ele : word){
                if(!cur->next[ele - 'a'])
                    return false;
                cur = cur->next[ele - 'a'];
            }
            return cur->isLeaf;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode* cur = root;
            for(auto ele : prefix){
                if(!cur->next[ele - 'a'])
                    return false;
                cur = cur->next[ele - 'a'];
            }
            return true;        
        }

    private:
        TrieNode* root;
};

/**
 *  * Your Trie object will be instantiated and called as such:
 *   * Trie obj = new Trie();
 *    * obj.insert(word);
 *     * bool param_2 = obj.search(word);
 *      * bool param_3 = obj.startsWith(prefix);
 *       */
