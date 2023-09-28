class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return nums;

        int evenIndex = 0;
        int oddIndex = n-1;
        vector<int> solution(n);
        
        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == 0) 
            {
                solution[evenIndex] = nums[i];
                evenIndex++;
            } 
            else 
            {
                solution[oddIndex] = nums[i];
                oddIndex--;
            }

        }

        return solution;
    }
};
