class Solution {

private:
int helper(vector<int>&nums, int start, int end)
{
        int currMax = 0, prevMax = 0;

        for(int i=start;i<end;i++)
        {
            int temp = currMax;
            currMax = max(currMax, nums[i] + prevMax);
            prevMax = temp;
        }

        return currMax;
}
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return nums[0];

        //ignore the last house
        int max1 = helper(nums,0,n-1);
        //ignore the first house
        int max2 = helper(nums,1,n);

        return max(max1,max2);
    }
};
