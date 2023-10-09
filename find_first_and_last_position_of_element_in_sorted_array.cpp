class Solution {
private:
    //this functions finds the leftmost index of target in nums, if it exists
    int binarySearchLeft(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;
        int left_index = -1;

        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                left_index = mid;
                //search for target in the left subarray to find the starting index
                r = mid - 1;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return left_index;
    }

    //this functions finds the rightmost index of target in nums, if it exists
    int binarySearchRight(vector<int>& nums, int target) {

        int l = 0, r = nums.size()-1;
        int right_index = -1;

        while(l <= r) {

            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                right_index = mid;
                //search for the end index of target in the right subarray now
                l = mid + 1;
            }
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return right_index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int nums_size = nums.size();
        if(nums_size == 0)
            return {-1,-1};
        
        if(nums_size == 1)
        {
            if(nums[0] == target)
                return {0,0};
            return {-1,-1};
        }

        int start = binarySearchLeft(nums, target);
        int end = binarySearchRight(nums, target);

        if(start <= end)
            return {start, end};
        return {-1,-1};
    
    }
};
