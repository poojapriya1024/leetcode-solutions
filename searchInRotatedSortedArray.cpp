class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int n = nums.size();
        if(n == 1)
            return nums[0];

        int l = 0, r = n - 1;

        while(l < r)
        {
            int mid = (l + r)/2;

            if(nums[mid] > nums[r]) //pivot is in right subarray
                l = mid + 1;
            else  //search in the left subarray 
                r = mid;
        }

        return nums[l];
           
    }
};
