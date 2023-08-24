class Solution {
public:
    int characterReplacement(string s, int k) {
        
        if(s.size() == 1)
            return 1;   //trivial case

        
        int start = 0, end = 0;
        int maxFreq = 0, maxLength = 1, windowSize = 1;

        vector<int> freq(26);

        while(end < s.size())
        {
            //increment the frequency of the current character
            freq[s[end] - 'A']++;

            //find the maximu  frequency
            maxFreq = max(maxFreq, freq[s[end] - 'A']);

            //window size = end - start + 1
            // windowSize - maxFreq gives us the number of characters to replace 
            while((end - start + 1) - maxFreq > k) 
            {
                //reduce the size of the window by popping elements from front
                freq[ s[start] - 'A']--;
                start++;
            }

            //compare the current window size against the max window size
            maxLength = max(maxLength, end - start + 1); 
            end++;
        }
        
        return maxLength;
    }
};
