class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> dp(numRows);

        for(int i=0;i<numRows;i++) {

            dp[i].resize(i+1);
            dp[i][0] = dp[i][i] = 1;

            for(int k = 1;k<i;k++) {
                dp[i][k] = dp[i-1][k-1] + dp[i-1][k];
            }
        }

        return dp;
    }
};
