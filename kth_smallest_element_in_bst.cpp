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
    void getInorder(TreeNode* root, vector<int>& inorderTraversal)
    {
        if(root == nullptr)
            return;
        
        getInorder(root->left,inorderTraversal);
        inorderTraversal.push_back(root->val);
        getInorder(root->right,inorderTraversal);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> inorderTraversal;
        getInorder(root,inorderTraversal);
        return inorderTraversal[k-1]; //as it is 1-indexed
    }
};
