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
    bool dfs(TreeNode* root, TreeNode* lRoot, TreeNode* rRoot) {

        if(root == nullptr)
            return true;

        // if left subtree exists and its value is greater than root, return false
        bool isLchild = (lRoot != nullptr && lRoot->val >= root->val);
        //if right subtree exists and its value is lesser than the root, return false
        bool isRchild = (rRoot != nullptr && rRoot->val <= root->val);

        if(isLchild || isRchild)
            return false;

        // else, check if the subtrees are also bst
        return (dfs(root->left, lRoot, root) &&
                dfs(root->right, root, rRoot));  
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,nullptr,nullptr);
    }
};
