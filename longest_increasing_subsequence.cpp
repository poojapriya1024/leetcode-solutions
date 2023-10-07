class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return 1;
        
        vector<int> dp(n,1);
        int maxLength = 1;

        for(int i=1;i<n;i++) {
            //compare all the elements from the beginning against nums[i] 
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]) //strictly increasing
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            maxLength = max(maxLength, dp[i]);
            
        }
        return maxLength;
    }
};
