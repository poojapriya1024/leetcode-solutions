class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int slen = s.size();
        if(slen == 0 || slen == 1)
            return slen;

        int start = 0, end = 0, maxLen = 1;

        //initialize the hash set
        set<char> seen;

        while(end < slen)
        {
            while( seen.find(s[end]) != seen.end() ) 
            {
                // till the character is repeated, remove character at start from the hash set
                seen.erase(s[start]);
                start++;
            }

            //insert the character at end
            seen.insert(s[end]);

            //compare the index of the current window with maxLen
            maxLen = max(maxLen, end-start+1);
            end++;

        }

        return maxLen;
    }
};
