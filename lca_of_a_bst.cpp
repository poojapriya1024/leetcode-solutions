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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // if either p or q is equal to root, then root is the LCA(p,q)
        if ((root->val == p->val) || (root->val == q->val)) 
            return root;
        
        // check if both the trees are present in the same subtree or not 
        if ( (root->val < p->val && root->val > q->val) ||
              (root->val < q->val && root->val > p->val) )
            
        return root;

        // if they are in the left subtree
        if(root->val > p->val)  
            return lowestCommonAncestor(root->left,p,q);
        //else, search in the right subtree
        return lowestCommonAncestor(root->right,p,q);


    }
};
