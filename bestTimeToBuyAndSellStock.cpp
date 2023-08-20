class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = prices[0], maxProfit = 0;

        for(int i=0;i<prices.size();i++)
        {
            if(minPrice > prices[i])
            // make this as the min price
            {
                minPrice = prices[i];
            }

            else
                maxProfit = max(maxProfit, prices[i] - minPrice);

        }

        
        return maxProfit;
    }
};
