class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int len = nums.size();
        if(k == 0)
            return 0;
        if(len == 1)
            return (nums[0] < k) ? 1 : 0;
        
        int solution = 0,l=0,r=0;
        int curr_pdt = 1;

        while(r < len)
        {   
            if(r != 0 && nums[r] < k)
                solution++; //for individual subarrays

            if(curr_pdt * nums[r] < k)
            {
                curr_pdt *= nums[r]; //update curr_pdt
                solution++;
            } else
            {   
                if(r == 0)
                {
                    r++;
                    continue;
                }

                if(l<len && l != r && nums[l] != 0)
                    curr_pdt /= nums[l];
                l++;
                continue;
            }

            r++;

        }
        return solution;
        
    }
};
