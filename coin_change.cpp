class Solution {
private:
    void dfs(vector<int>& coins, int amount, vector<int>& curr, int& solution,long long sum)
    {  
        if(sum > amount)
            return;
        
        if(sum == amount) {
            //check if we can reach the amount with fewer number of coins
            if(curr.size() < solution)
                solution = curr.size();
        }

        for(int i=0;i<coins.size();i++) {
            //add the current element to our current sum
            curr.push_back(coins[i]);
            dfs(coins,amount,curr,solution,sum + coins[i]);
            curr.pop_back();
        }
    }
public:
    bool compareDesc(int x,int y)
    {
        return x>y;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) 
            return 0;

        int n = coins.size();
        // if(n == 1) 
        //     return coins[0] == amount? 1:-1;

        //sort the array in descending order
         sort(coins.begin(), coins.end(), [](int x, int y) {
            return x > y;
        });

        vector<int> curr;
        int solution = -1;
        dfs(coins,amount,curr,solution,0ll);
        return solution;

        
    }
};
