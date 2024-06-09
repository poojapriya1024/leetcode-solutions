class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n == 1)
            return (nums[0] % k == 0) ? 1 : 0;

        unordered_map<int,int> map;
        map.insert({0, 1});

        int solution = 0, curr_sum = 0;

        for(int i=0;i<nums.size();i++)
        {
            curr_sum += nums[i];
            int curr_rem = (curr_sum % k + k) % k;

            if(map.find(curr_rem) != map.end())
                solution += map[curr_rem];

            map[curr_rem]++;
        }

        return solution;
    }
};
