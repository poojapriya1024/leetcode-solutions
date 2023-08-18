class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int n = nums.size();
        if(n == 1)
            return nums[0];

        int pivot = 0;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1])
            {
                pivot = i + 1;
                break;
            }
        }

        return nums[pivot];
           
    }
};
