class Solution {
  private:
    int minCost(vector<int>& arr, int i, int j, vector<vector<int>>& dp)
    {
        if(i == j) return 0; //single array
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int cost = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int currCost = arr[i-1] * arr[k] * arr[j] + 
                            minCost(arr,i,k,dp) + minCost(arr,k+1,j,dp);
            cost = min(cost, currCost);
        }
        
        return dp[i][j] = cost;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return minCost(arr,1,n-1,dp);
        
    }
};
