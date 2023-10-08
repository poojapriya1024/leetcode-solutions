class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int a = nums1.size();
        int b = nums2.size();

        if(a == 1 && b == 1)
            return nums1[0] * nums2[0];

        //create a 2d array with a+1 rows and b+1 columns
        //and assign each cell to a value of LLONG_MIN
        vector<vector<long long>> dp(a+1, vector<long long>(b+1, LLONG_MIN));

        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                long long temp = nums1[i-1]*nums2[j-1];
                dp[i][j] = max(dp[i][j], temp);

                //add diagonal value to current product only if it is not LLONG_MIN
                if(dp[i-1][j-1] != LLONG_MIN)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+temp);

                //compare with left cell
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                //compare with top cell
                dp[i][j] = max(dp[i][j],dp[i-1][j]);

            }
        }

        return dp[a][b];
    }
};
