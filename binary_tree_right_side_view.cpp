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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> solution;

        if(root == nullptr)
            return solution;

        //perform bfs
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int currSize = q.size();
            int i = 1;

            solution.push_back(q.back()->val);
            while(i <= currSize)
            {
                TreeNode* currNode = q.front();
                q.pop();

                // add the left subtree if it is not null
                if(currNode->left != nullptr)
                    q.push(currNode->left);
                // add the right subtree if it is not null
                if(currNode->right != nullptr)
                    q.push(currNode->right);

                i++;
            }
        }

        return solution;
    
    }
};
