class Solution {
private:
    void dfs(vector<int>& candidates,vector<int>& curr,vector<vector<int>>& solution, int start, int sum, int target) {

        if(sum == target)
        {
            solution.push_back(curr);
            return;
        }
        if(sum > target)
            return;

        for(int i=start;i<candidates.size();i++) {
            //find all possible subsets with candidates[i] included in the sum
            curr.push_back(candidates[i]);
            dfs(candidates, curr,solution,i,sum + candidates[i],target);
            //now, find all possible subsets with candidate[i] not included in the sum
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> solution;
        vector<int> curr;
        dfs(candidates,curr,solution,0,0,target);
        return solution;
    }
};
