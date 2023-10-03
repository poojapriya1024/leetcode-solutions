class Solution {
private:
    void transposeMatrix(vector<vector<int>>& matrix) {
    
    int n = matrix.size();
    
    for(int x=0;x<n;x++)
    {
        for(int y=x+1;y<n;y++)
            swap(matrix[x][y], matrix[y][x]);
    }

    }
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n == 1)
            return;
        
        //transpose the current matrix
        transposeMatrix(matrix);
    
        //reverse all the rows in the transposed matrix
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(), matrix[i].end());

    }
};
