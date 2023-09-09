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
    int dfs(TreeNode* root, int& count, int maxSoFar) {
        
    if(root == nullptr)
        return count;

    if(root->val >= maxSoFar)
    {
        count++;
        maxSoFar = root->val;
    }

    dfs(root->left, count, maxSoFar);
    dfs(root->right, count, maxSoFar);

    return count;

    }

public:
    int goodNodes(TreeNode* root) {

        int maxSoFar = INT_MIN;
        int count = 0;

        return dfs(root, count, maxSoFar);

    }
};
