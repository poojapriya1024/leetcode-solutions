/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void largestValuesHelper(TreeNode* root, vector<int>& solution) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            //this is to make sure we only iterate through the current level
            int currSize = q.size(); 
            int j = 0, tempMax = INT_MIN;
            bool foundMax = 0;
            //this loop iterates through all elements in the current level
            while(j < currSize) {

                TreeNode* curr = q.front();
                //remove the current node immediately 
                q.pop(); 

                if(curr != nullptr) {
                    //find the maximum in the current row/level
                    if(curr->val >= tempMax) {
                        tempMax = curr->val;
                        foundMax = 1;

                    }
                    
                    //push it's child nodes to the queue
                    q.push(curr->left);
                    q.push(curr->right);
                }

                j++;

            }

            //add the maximum element of this row to solution
            if(foundMax)
                solution.push_back(tempMax);
        }

        return;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> solution;
        if(root == nullptr)
            return solution;
        
        largestValuesHelper(root, solution);
        return solution;
        
    }
};
