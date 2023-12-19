class Solution {
private:
    vector<pair<int,int>> dir = {{-1,-1},{-1,0},{0,-1},{1,1},{1,0},{0,1},{1,-1},{-1,1}};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int row = img.size();
        int col = img[0].size();

        vector<vector<int>> solution(row, vector<int>(col,0));

        if(row == 1 && col == 1)
            return img;

        for(int i=0;i<row;i++) 
        {
            for(int j=0;j<col;j++)
                {
                    int sum = img[i][j];
                    int count = 1;

                    //check if the cells surrounding the current cells are valid
                    for(auto &d : dir)
                    {   
                        int ni = d.first + i;
                        int nj = d.second + j;
                        
                        if(ni >= 0 && ni < row && nj >= 0 && nj < col)
                        {
                            sum += img[ni][nj];
                            count++;
                        }
                    }

                    solution[i][j] = (sum/count);
                }
        } 

        return solution;
    }
};
