class Solution {
private:
    vector<vector<int>> shortestCommonSupersequenceHelper(string str1, string str2)
    {
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));

        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        vector<vector<int>> dp = shortestCommonSupersequenceHelper(str1, str2);
        //calculating the shortest common subsequence from the tabulation dp table

        string solution = "";
        int i = str1.length(), j = str2.length();

        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                solution = str1[i-1] + solution;
                i--;
                j--;
            } else {

                int left = dp[i][j-1], up = dp[i-1][j];
                if(left < up) {

                    solution = str1[i-1] + solution; 
                    i--;
                } else {

                    solution = str2[j-1] + solution;
                    j--;

                }
            }
        }

        while(i > 0)
        {
            solution = str1[i-1] + solution;
            i--;
        }

        while(j > 0)
        {
            solution = str2[j-1] + solution;
            j--;
        }

        return solution;

    }
};
