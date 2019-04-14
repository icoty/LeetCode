#include "AllInclude.h"

class Solution {
    public: // https://www.cnblogs.com/zmyvszk/p/5516174.html
        int ladderLength(string beginWord, string endWord, vector<string>& lists) {
            unordered_set<string> wordList(lists.begin(), lists.end());
            queue<string> Q;
            set<string> visited;
            Q.push(beginWord);
            visited.insert(beginWord);
            int cnt = 1;
            while(!Q.empty()){
                cnt++;
                int size = Q.size();
                while(size--){
                    string front = Q.front();
                    Q.pop();
                    for(int i = 0; i < front.size(); i++){
                        for(char ch = 'a'; ch <= 'z'; ch++){
                            if(ch == front[i]) 
                                continue;
                            string tmp = front;
                            tmp[i] = ch;
                            if(wordList.count(tmp) && !visited.count(tmp)){
                                if(tmp == endWord)
                                    return cnt;
                                Q.push(tmp);
                                visited.insert(tmp);
                            }
                        }
                    }
                }
            }
            return 0;
        }
};
