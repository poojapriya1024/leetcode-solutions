class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        //initializing a 2D array with rowindex+1 rows and empty inner vectors
        vector<vector<int>> dp(rowIndex+1);

        for(int i=0;i<rowIndex+1;i++) {

            //resize the inner vector
            dp[i].resize(i+1);
            //in pascal's triangle, first and last column of any row is 1
            dp[i][0] = dp[i][i] = 1;

            for(int j=1;j<i;j++) 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }

        return dp[rowIndex];
    }
};
