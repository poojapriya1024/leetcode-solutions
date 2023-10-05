class Solution {
private:
    bool inDict(string word, vector<string>& wordDict) {

        for(auto &el: wordDict) {
            if(el == word)
                return true;
        }

        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int slen = s.length();
        if(slen == 1)
            return inDict(s,wordDict);

        vector<bool> dp(slen+1, false);
        dp[0] = true; //always true for empty string 

        for(int end=0;end<slen;end++)
        {
            for(int start=end; start>=0; start--)
            {
                if(dp[start])
                {
                    string curr_word = s.substr(start, end-start+1);
                    if(inDict(curr_word, wordDict))
                    {
                        dp[end+1] = true;
                        break; //further searching is not required
                    }
                }
            }
        }

        return dp[slen];
    }
};
