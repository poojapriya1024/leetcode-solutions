#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int column = matrix[0].size();

        //find the row which will possibly contain the target
        
        int index = -1;
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0] <= target && matrix[i][column-1] >= target) {
                index = i;
                break;
            }
        }

        if(index == -1)
            return false;

        int l = 0, r = column-1;

        while(l <= r)
        {
            int mid = l + (r - l)/2;
            
            if(matrix[index][mid] > target)
                r = mid - 1;
            else if(matrix[index][mid] < target)
                l = mid + 1;
            else
                return true;
        }

        return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    bool flag = searchMatrix(matrix, );

    cout<<flag;
    return 0;

}