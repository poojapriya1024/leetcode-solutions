class Solution {
    
private:
void backtrack(vector<int>& nums,vector<vector<int>>& solution, vector<int>& curr, vector<bool>& used) {
 
    // this is a possible permutation
    if(curr.size() == nums.size()) {
        solution.push_back(curr);
        return;
    }

    for(int i=0;i<nums.size();i++) {


        if(used[i]) //if the element is already in our current permutation
            continue;

        //else, include the element
        curr.push_back(nums[i]);
        used[i] = true;

        backtrack(nums,solution,curr,used);
        //backtrack
        curr.pop_back();
        used[i] = false;

    }

}
public:
    vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> solution;
    // this tores the current permutation
    vector<int> curr; 
    //keeps track of the elements that are already in the current permutation
    vector<bool> used(nums.size(),false);

    backtrack(nums,solution,curr,used);
    return solution;
}
};
