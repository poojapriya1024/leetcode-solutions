class Solution {
private:
    void backtrack(vector<int> nums,vector<vector<int>>& solution,vector<int>& curr, vector<bool>& visited) {
      
        if(curr.size() == nums.size())
        {       
            solution.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            
            bool isDuplicate = ( (i != 0 && nums[i] == nums[i-1]) && !visited[i-1]);
            if(visited[i] || isDuplicate)
                continue;
                

            int temp = nums[i];
            curr.push_back(temp);
            visited[i] = true;
            backtrack(nums,solution,curr,visited);
            visited[i] = false;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> solution;
        int n = nums.size();

        if(n == 1)
        {
            solution.push_back(nums);
            return solution;
        }

        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<bool> visited(n,false);
        backtrack(nums,solution,curr,visited);

        return solution;


    }
};
