class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int farthest = 0, end = 0, minJumps = 0;

        //till n-1 as we need to find jumps needed to reach n-1
        for(int start=0;start<n-1;start++)
        {
            farthest = max(farthest, start + nums[start]);

            if(start == end)
            {
                minJumps++;
                end = farthest;
            }
        }
        return minJumps;

    }
};
