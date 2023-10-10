class Solution {
private:
    void transposeMatrix(vector<vector<int>>& matrix, vector<vector<int>>& solution) {

        int sol_row = matrix[0].size();
        int sol_col = matrix.size();

        for(int i=0;i<sol_row;i++) {
            for(int j=0;j<sol_col;j++) {
                solution[i][j] = matrix[j][i];
            }
        }
    }
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //col

        vector<vector<int>> solution(n, vector<int>(m)); 
        transposeMatrix(matrix, solution);
        return solution;

    }
};
