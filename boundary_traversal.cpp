/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    bool isLeaf(Node* node)
    {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    void leftTraversal(Node* root, vector<int>& arr)
    {   
        Node* curr = root->left;
        
        while(curr)
        {
            if(!isLeaf(curr))   
                arr.push_back(curr->data);
            
            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    
    
    void leafNodes(Node* root, vector<int>& arr)
    {
        if (root == nullptr)
            return;
    
        if (isLeaf(root)) {
            arr.push_back(root->data);
            return;
        }
    
        leafNodes(root->left, arr);
        leafNodes(root->right, arr);
    }

    
    void rightTraversal(Node* root, vector<int>& solution)
    {
        vector<int> arr;
        Node* curr = root->right;
        
        while(curr)
        {
            if(!isLeaf(curr))
                arr.push_back(curr->data);
                
            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        reverse(arr.begin(), arr.end());
        for(int i: arr)
            solution.push_back(i);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        
        if(root == nullptr)
            return {};
        
        if(!root->left && !root->right)
            return {root->data};
        
        //1. root 2. left traversal
        //3. leaf nodes 4. reverse right traversal
        
        vector<int> solution;
        solution.push_back(root->data);
        
        leftTraversal(root, solution);
        leafNodes(root, solution);
        rightTraversal(root, solution);
            
        return solution;
        
    }
};
