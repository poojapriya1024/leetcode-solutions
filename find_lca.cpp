#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

bool findLCA(TreeNode* root, int k, vector<int>& path)
{
    if(root == nullptr) return false;
    path.push_back(root->data);
    
    if(root->data == k) return true;
    if(findLCA(root->left,k,path) || findLCA(root->right, k, path)) 
        return true;
    
    path.pop_back();
    return false;
}

void printArr(vector<int> arr)
{
    for(int num : arr)
        cout<<num<<" ";
    cout<<endl;
}
int main() {
    // Write C++ code here
    TreeNode* root = new TreeNode(3);
    
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    vector<int> path1, path2;
    
    if (findLCA(root, 8, path1) && findLCA(root, 0, path2))
    {
        printArr(path1);
        printArr(path2);
    }
        

    return 0;
}
