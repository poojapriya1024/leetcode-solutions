class Solution {
private:
    int count;
    void expandAroundCenter(string s,int start, int end) {

        while(start >= 0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
            count++;
        }

    }
public:
    int countSubstrings(string s) {

        int slen = s.length();
        if(slen == 1)
            return slen;

        count = 0;
        for(int i=0;i<slen;i++) {

            //for odd length palindromes
            expandAroundCenter(s,i,i);
            //for even length palindromes
            expandAroundCenter(s,i,i+1);
        }

        return count;
        
        
    }
};
