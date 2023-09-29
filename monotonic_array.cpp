class Solution {
public:
    bool isMonotoneIncreasing(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=1;i<n;i++) 
        {
            if(nums[i] < nums[i-1])
                return false;
        }

        return true;
    }

    bool isMonotoneDecreasing(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=1;i<n;i++) 
        {
            if(nums[i] > nums[i-1])
                return false;
        }

        return true;
    }

    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return true;

        bool result = isMonotoneDecreasing(nums) || isMonotoneIncreasing(nums);
        return result;
        

    }
};
