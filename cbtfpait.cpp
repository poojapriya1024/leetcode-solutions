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

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,
    int preStart, int preEnd, int inStart, int inEnd) {

        if(preStart > preEnd || inStart > inEnd)
            return nullptr;

        // the first element in the preorder traversal is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        //then, find the index of the root in the inorder traversal
        int rootIndex = inStart;

        while(inorder[rootIndex] != preorder[preStart])
            rootIndex++;

        //this is the number of nodes in the left subtree of root
        int count = rootIndex - inStart;

        //recursive call for left subtree
        root->left = dfs(preorder,inorder,preStart+1,preStart+1+count,inStart,rootIndex-1);
        //recursive call for right subtree
        root->right = dfs(preorder,inorder,preStart+count+1,preEnd,rootIndex+1,inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        return dfs(preorder,inorder,0,n-1,0,n-1);
    }
};
