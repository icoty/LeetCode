#include "AllInclude.h"

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto & ele : dict){
            mp[ele.size()].push_back(ele);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(!mp.count(word.size()))
            return false;
        
        for(auto & ele : mp[word.size()]){
            int cnt = 0;
            for(int i = 0; i < ele.size(); ++i){
                if(word[i] != ele[i])
                    ++cnt;
                if(cnt > 1)
                    break;
            }
            
            if(cnt == 1)
                return true;
        }
        
        return false;
    }
    
    unordered_map<int, vector<string>> mp;
};
