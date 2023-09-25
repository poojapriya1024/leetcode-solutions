class Solution {
private:
    int maxStart;
    int maxLength;

    // this function finds the length of the longest palindrome
    // with (start,end) as the center 
    void palindromeHelper(string s, int start, int end)
    {
        while(start >= 0 && end < s.length() && s[start] == s[end])
        {
            start--;
            end++;
        }

        // after the end of this while loop, start and end are either out of bounds or 
        // not a part of palindrome 

        if(end - start - 1 > maxLength) {
        maxStart = start + 1;
        // end - start - 1 => length of the palindrome in this case
        maxLength = end - start - 1;
    }

}
public:
    string longestPalindrome(string s) {
        
        int slen = s.length();
        if(slen == 1)
            return s;

        maxStart = 0;
        maxLength = 0;

        for(int i=0;i<slen;i++) {
            //consider each character as the center of the palindrome

            //for odd palindromes
            palindromeHelper(s,i,i);
            //for even palindromes
            palindromeHelper(s,i,i+1);
        }
        
        return s.substr(maxStart, maxLength);
    }
};
