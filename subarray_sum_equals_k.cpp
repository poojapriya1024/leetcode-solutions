/*Intuition is that if there exists two subarrays ending at index i and index j respectively where i < j, then if sum(subarray1) - sum(subarray2) = k, then the subarray starting at i and ending at j will have the sum of k*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1)
            return nums[0] == k? 1:0;

        unordered_map<int,int> map;
        int solution = 0;
        int currSum = 0;

        for(int i=0;i<n;i++)
        {
           currSum += nums[i];
           if(currSum == k)
                solution++;

            int temp = currSum - k;
            //there already exists one or more contiguous subarray with sum = temp
            if(map.find(temp) != map.end())
            {
                solution += map[temp];
            }

            map[currSum]++;
        }

        return solution;


    }
};
