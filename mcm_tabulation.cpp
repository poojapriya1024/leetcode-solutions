class Solution {
  private:
    int n;
    void findMinCost(vector<int>& arr, vector<vector<int>>& dp)
    {
        //m - number of matrices we are multiplying now
        for(int m=2;m<n;m++)
        {
            //we are multiplying matrix i and i + m
            for(int i=1;i<n-m+1;i++)
            {
                int j = i + (m - 1);
                int cost = INT_MAX;
                //we are multiplying matrix i to matrix j through k
                for(int k=i;k<j;k++)
                {
                    int temp = arr[i-1]*arr[k]*arr[j] + 
                                dp[i][k] + dp[k+1][j];
                    cost = min(cost, temp);
                }
                
                dp[i][j] = cost;
                
            }
        }
        
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        findMinCost(arr, dp);
        
        return dp[1][n-1];
        
        
        
    }
};
