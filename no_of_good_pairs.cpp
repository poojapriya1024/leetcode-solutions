class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return 0;
        
        unordered_map<int,int> map;
        int solution = 0;
    
        for(int i=0;i<n;i++) {

            int curr = nums[i];
            //check if this element is laready there in the hash map
            if(map.find(curr) != map.end()) {
                solution += map[curr];
            }

            map[curr]++;
        }

        return solution;
    }
};
