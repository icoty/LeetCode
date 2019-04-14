#include "AllInclude.h"

class Solution {
    public:
        Solution()
            :dict("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
        {
            long2short.clear();
            short2long.clear();
            srand(time(NULL));
        }

        string encode(string longUrl) {
            if(long2short.count(longUrl))
                return "http://tinyurl.com/" + long2short[longUrl];

            string randStr;
            do
            {
                randStr.clear();
                for(int i = 0; i < 6; ++i) 
                    randStr.push_back(dict[rand() % 62]);
            }while(short2long.count(randStr));

            short2long[randStr] = longUrl;
            long2short[longUrl] = randStr;
            return "http://tinyurl.com/" + randStr; 
        }

        string decode(string shortUrl) {
            string randStr = shortUrl.substr(shortUrl.size() - 6);
            return short2long.count(randStr) ? short2long[randStr] : shortUrl;   
        }

    private:
        unordered_map<string, string> long2short, short2long;
        string dict;
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string url = stringToString(line);

        string ret = Solution().CodecDriver(url);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
