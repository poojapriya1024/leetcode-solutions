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

    void getInorderTraversal(TreeNode* root, vector<int>& solution) {

        if(root == nullptr)
            return;
        
        getInorderTraversal(root->left, solution);
        solution.push_back(root->val);
        getInorderTraversal(root->right, solution);

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> solution;
        getInorderTraversal(root,solution);

        return solution;
    }
};
