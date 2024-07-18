class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m =  obstacleGrid.size(), n =  obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n,-1));
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                dp[i][j] = 0;

                if(j > 0)
                {
                    if(obstacleGrid[i][j-1] != 1 && dp[i][j-1] != -1)
                        dp[i][j] += dp[i][j-1]; //left cell

                }

                if(i > 0)
                {
                    if(obstacleGrid[i-1][j] != 1 && dp[i-1][j] != -1)
                        dp[i][j] += dp[i-1][j]; //the cell above
                }

            }
        }

        return dp[m-1][n-1];
    }
};
