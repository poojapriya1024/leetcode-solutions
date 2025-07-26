/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isPresent(TreeNode* root, int val)
    {
        if(root == nullptr) return false;

        if(root->val == val) return true;

        return (isPresent(root->left, val) || isPresent(root->right, val));
    }

    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr) return root;

        if(root == p || root == q)
            return root;
        
        TreeNode* findLeft = findLCA(root->left, p, q);
        TreeNode* findRight = findLCA(root->right, p, q);

        if(findLeft && findRight) return root;

        if(findLeft == nullptr) return findRight;
        return findLeft;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // if(isPresent(root, p->val) && isPresent(root, q->val))
        return findLCA(root, p, q);
    }
};
