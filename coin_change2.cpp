class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
            return 0;

        int n = coins.size();
        if(n == 1 && coins[0] == amount)
            return 1;

        //this vector will store the number of coins required to sum up to i
        //size = amount+1 becuase we find the min coins required for each value till amount, from 0
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0; //there is only way to sum upto 0 => use 0 coins

        //populate dp
        for(int x=1; x <= amount; x++) {
            for(int y=0;y<n;y++) {

                //we find if val = x - coins[y] is valid and if so, 
                //we add the coint with val = coins[y] and check if x - coins[y] is also present

                //we include coins[y]
                int temp = x - coins[y];
                if(temp >= 0) //if valid
                    dp[x] = min(dp[x], 1 + dp[temp]);
            }
        }

        if(dp[amount] > amount)
            return -1;
        return dp[amount];
        
    }
};
