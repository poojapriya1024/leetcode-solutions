class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;

        while(l <= r)
        {
            int m = l + (r - l)/2;

            if(nums[m] == target)
                return true;
            
            if(nums[l] == nums[m] && nums[m] == nums[r])
            {
                l++;
                r--;
                continue;
            }

            //left sorted portion [l,m]
            if(nums[l] <= nums[m])
            {
                if(nums[l] <= target && nums[m] >= target)
                    r = m - 1;
                else
                    l = m + 1;
            }
            //right sorted portion [m,r]
            else
            {
                if(nums[m] <= target && nums[r] >= target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return false;
    }
};


/* best example to understand
a = [3, 3, 3, 1, 2, 3], key = 1
l = 0, a[l] = 3
r = 5, a[r] = 3
m = 2, a[m] = 3
here, we can't proceed further as elements of l = m = r, so we shrink the window such that the condition a[l] = a[m] = a[r] is not valid anymore
*/
