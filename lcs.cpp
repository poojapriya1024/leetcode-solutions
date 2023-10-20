class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int a = text1.length();
        int b = text2.length();

        //initialize a 2D array for holding the max length
        vector<vector<int>> dp(a+1, vector<int>(b+1,0));

        for(int i = a-1; i>=0; i--) {

            for(int j=b-1;j>=0;j--) {
                
                if( text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];

                else {
                    int right = dp[i][j+1];
                    int down = dp[i+1][j];

                    dp[i][j] = max(right, down);
                }
                    
            }
        }

        return dp[0][0];
    }
};
