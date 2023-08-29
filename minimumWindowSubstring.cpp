class Solution {
public:

string minWindow(string s, string t) {
        
        // every character of t must be present in the substring of s
        int slen = s.size();
        int tlen = t.size();
 
        if(tlen > slen)
            return "";

        int start = 0, end = 0;
        int minLength = INT_MAX;
        int sol_start = 0; //represents the start of the minimum window substring 
        int matches = 0; // indicates the number of matches with the string t

        vector<int> freq(256,0); 

        // populate freq with the frequecies of the characters in t
        for(int i=0;i<tlen;i++)
            freq[t[i]]++;


        while(end < slen)
        {  
            // if the current character is present in t
            if(freq[s[end]] > 0)
                matches++;

            freq[s[end]]--; //indicating that end pointer has crossed it

            while(matches == tlen)
            {   
                // if the length of the current window is lesser than minLength
                if(minLength > end - start + 1)
                {
                    minLength = end - start + 1; //update minLength to the size of our current window
                    sol_start = start;  // now solution starts from index start
                }

                // now, start checking for smaller substrings by shrinking the window

                freq[s[start]]++; //indicating that the start pointer has crossed it

                if(freq[s[start]] > 0)
                    matches--;

                start++;
            }
                
            end++;
        }

        if(minLength == INT_MAX)
            return "";
        
        return s.substr(sol_start, minLength);

}
};
