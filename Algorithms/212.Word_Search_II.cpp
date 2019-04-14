#include "AllInclude.h"

class Node{
    public:
        vector<Node*> child;
        string str;

        Node()
            :str("")
        { 
            child.resize(26, 0);
        };

        ~Node()
        {
            for(auto & ele : child)
                if(ele) 
                    delete ele;
        }
};

class Trie{
    public:
        Node* root;

        Trie()
            :root(new Node())
        { }

        ~Trie()
        {
            if(root)
                delete root;
        }

        void insert(string s)
        {
            Node* cur = root;
            for(auto & ele : s)
            {
                if(!cur->child[ele - 'a'])
                    cur->child[ele - 'a'] = new Node();
                cur = cur->child[ele - 'a'];
            }
            cur->str = s;
        }
};

class Solution {
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            vector<string> ret;
            if(words.empty() || board.empty() || board[0].empty()) 
                return ret;
            Trie T;
            for(auto & ele : words)
                T.insert(ele);

            vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
            for(int i = 0; i < board.size(); ++i){
                for(int j = 0; j < board[0].size(); ++j){
                    if(T.root->child[board[i][j] - 'a'])
                        search(board, visit, T.root->child[board[i][j] - 'a'], i, j, ret);
                }
            }
            return ret;
        }

        void search(vector<vector<char>>& board, vector<vector<bool>>& visit, Node* cur, int r, int c, vector<string>& ret){
            if(!cur->str.empty()){
                ret.push_back(cur->str);
                cur->str.clear();   // The same letter cell may not be used more than once in a word
            }

            int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            visit[r][c] = true;
            for(auto &a : d) {
                int nr = a[0] + r, nc = a[1] + c;
                if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && !visit[nr][nc] && cur->child[board[nr][nc] - 'a']) {
                    search(board, visit, cur->child[board[nr][nc] - 'a'], nr, nc, ret);
                }
            }
            visit[r][c] = false;        
        }
};
