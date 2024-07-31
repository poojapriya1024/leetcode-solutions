class Solution {
private:
    int longestPalindromicSubsequence(string s)
    {
        string rs = s;
        reverse(rs.begin(), rs.end());

        int len = s.length();
        vector<int> prev(len+1,0), curr(len+1,0);

        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=len;j++)
            {
                if(s[i-1] == rs[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }

        return curr[len];
    }
public:
    int minInsertions(string s) {

        int lps = longestPalindromicSubsequence(s);
        return s.length() - lps;

    }
};
