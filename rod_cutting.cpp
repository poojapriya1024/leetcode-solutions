// User function Template for C++

class Solution {
  private:
    int W;
    int dfs(int idx,int cap,vector<int> &price, vector<vector<int>>& dp)
    {
        if(idx == 0) return dp[idx][cap] = price[0] * cap; //length 1 
        if(cap == 0) return dp[idx][cap] = 0;
        
        if(dp[idx][cap] != -1) 
            return dp[idx][cap];
        
        //we can either cut rod here or we can not
        int rod_length = idx + 1;
        int choose = 0;
        if(cap >= rod_length)
            choose = price[idx] + dfs(idx,cap-rod_length, price, dp);
            
        int not_choose = dfs(idx-1,cap,price, dp);
        
        return dp[idx][cap] = max(choose, not_choose);
        
        
    }
  public:
    int cutRod(vector<int> &price) {
        
        W = price.size();
        vector<vector<int>> dp(W, vector<int>(W+1, -1));
        
        int solution = dfs(W-1, W, price,dp);
        
        return solution;
        
    }
};
