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

    void findLeafSeq(TreeNode* root, vector<int>& seq)
    {
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr)
        {
            //if it is a leaf node, add to the vector
            seq.push_back(root->val);
            return;

        }        
        if(root->left != nullptr)
                findLeafSeq(root->left,seq);
                
        if (root->right != nullptr)
            findLeafSeq(root->right,seq);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> seq1;
        findLeafSeq(root1, seq1);
        vector<int> seq2;
        findLeafSeq(root2,seq2);

        if(seq1.size() != seq2.size())
            return false;

        for(int i=0;i<seq1.size();i++)
        {
            if(seq1[i] != seq2[i])
                return false;
        }

        return true;

    }
};
