/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  private:
    Node* leftMost(Node* root)
    {
        while(root->left)
            root = root->left;
        
        return root;
    }
    
    Node* rightMost(Node* root)
    {
        while(root->right)
            root = root->right;
        
        return root;
    }
    
    vector<Node*> findPreSucHelper(Node* root, int key)
    {
        if(root == nullptr) return {};
        
        Node* pred = nullptr;
        Node* succ = nullptr;
        
        while(root != nullptr)
        {
            if(root->data < key)
            {
                //search right
                pred = root;
                root = root->right;
            }
            else if(root->data > key)
            {
                //search left
                succ = root;
                root = root->left;
            }
            else
            {
                //if key is found
                if(root->right) 
                    succ = leftMost(root->right);
                if(root->left)
                    pred = rightMost(root->left);
                break;
            }
        }
        
        return {pred, succ};
        
        
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        
        return findPreSucHelper(root, key);
        
    }
};
