#include "AllInclude.h"

class Solution {
    public:
        bool isLetter(char& ch)
        {
            ch = tolower(ch);
            return (ch >= 'a' && ch <='z');
        }

        string mostCommonWord(string paragraph, vector<string>& banned) {
            int i = 0;
            while(i < paragraph.size()){
                if(!isLetter(paragraph[i]))
                    paragraph[i] = ' ';
                ++i;
            }
            set<string> bans;
            for(auto ele : banned)
                bans.insert(ele);

            map<string, int> freq;
            istringstream in(paragraph);
            string word;
            pair<string, int> max("", 0);
            while(in >> word){
                if(0 == bans.count(word)){
                    if(++freq[word] > max.second){
                        max  = {word, freq[word]};

                    }
                }
            }
            return max.first;
        }
};
