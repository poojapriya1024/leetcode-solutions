class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int len = s.length();
        if(len == 1)
            return abs(int(s[0]) - int(t[0])) <= maxCost ? 1 : 0;
        
        int maxLen = 0, l = 0, currCost = 0;

        for(int r=0;r<len;r++)
        {
            int diff = abs(int(s[r]) - int(t[r]));
            currCost += diff;

            while(currCost > maxCost)
            {
                currCost -= abs(int(s[l]) - int(t[l]));
                l++;
            }

            maxLen = max(maxLen, r-l+1);

        }

        return maxLen;

    }
};
