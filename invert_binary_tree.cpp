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
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr)
            return root;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // recursively call the function for left and right sub trees
        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};
