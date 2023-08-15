class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;
        vector<vector<int>> solution;
        dfs(nums,0,subset,solution);

        return solution;
    }


private:

    void dfs(vector<int> nums,int start, vector<int>& curr, vector<vector<int>>& solution)
    {
        solution.push_back(curr);

        for(int i=start;i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            dfs(nums,i+1,curr,solution);
            curr.pop_back();
        }
        
    }
};
