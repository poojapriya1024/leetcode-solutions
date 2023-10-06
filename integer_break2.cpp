class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i=3;i<=n;i++)
        {   
            //trying all combinations for sum = i to get maximum product
            for(int j=1;j<i;j++)
            {
                int curr_pdt = j * max(i-j, dp[i-j]);
                dp[i] = max(dp[i], curr_pdt);
            }
        }

        return dp[n];
    }
};
