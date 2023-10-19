lass Solution {
private:
int uniquePathsHelper(int m, int n, vector<vector<int>>& dp) {

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {

                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(i > 0)
                    up = dp[i-1][j];
                if(j > 0)
                    left = dp[i][j-1];

                // no of ways to reach the left most cell by moving up + moving left
                dp[i][j] = up + left; 
            }
        }

        return dp[m-1][n-1];
}

public:
int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int solution = uniquePathsHelper(m,n, dp);
        return solution;
    }
};
