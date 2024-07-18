class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                    continue;
                }

                int left = INT_MAX, up = INT_MAX;
                if(j > 0 && dp[i][j-1] != -1)
                    left = dp[i][j-1];
                
                if(i > 0 && dp[i-1][j] != -1)
                    up = dp[i-1][j];

                dp[i][j] = min(left, up) + grid[i][j];

            }
        }

        return dp[m-1][n-1];
    }
};
