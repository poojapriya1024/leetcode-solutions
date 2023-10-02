class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int currMax = 1, currMin = 1;
        int solution = nums[0];

        for(int i=0;i<n;i++) {

            int tempMin = currMin * nums[i];

            currMin = min(currMin * nums[i], min(currMax * nums[i], nums[i]));
            currMax = max(tempMin, max(currMax * nums[i], nums[i]));
            solution = max(solution, currMax);
        }

        return solution;
    }
};
