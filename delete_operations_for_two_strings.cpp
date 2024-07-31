class Solution {
private:
    int longestCommonSubsequnce(string x, string y)
    {
        int xlen = x.length(), ylen = y.length();
        vector<int> prev(ylen+1,0), curr(ylen+1,0);

        for(int i=1;i<=xlen;i++)
        {
            for(int j=1;j<=ylen;j++)
            {
                if(x[i-1] == y[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[ylen];
    }
public:
    int minDistance(string word1, string word2) {
        
        int len1 = word1.length(), len2 = word2.length();
        int lcs = longestCommonSubsequnce(word1, word2);
        return (len1-lcs + len2-lcs);
    }
};
