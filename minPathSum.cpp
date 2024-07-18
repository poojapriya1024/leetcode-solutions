#include<bits/stdc++.h>
using namespace std;

void printArray(int m, int n,vector<vector<int>> arr)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int minPathSumHelper(int m, int n, vector<vector<int>>& mat,
                                    vector<vector<int>>& dp)
{   
    if(m < 0 || n < 0)
        return 0;
    
    // if(m == 0 && n == 0)
    //     return dp[0][0] = mat[0][0];
    
    if(dp[m][n] != -1)
        return dp[m][n];
        
    int left = 0, up = 0;
    if(n > 0)
        left = minPathSumHelper(m,n-1,mat,dp);
    if(m > 0)
        up = minPathSumHelper(m-1,n,mat,dp);
    
    if(left == 0)
        return dp[m][n] = up + mat[m][n];
    if(up == 0)
        return dp[m][n] = left + mat[m][n];
    
    return dp[m][n] = min(left, up) + mat[m][n];
    
}
int minPathSum(vector<vector<int>>& mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    dp[0][0] = mat[0][0];
    int solution = minPathSumHelper(m-1,n-1,mat,dp);
    printArray(m,n,dp);
    return solution;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6}};
    int min_sum = minPathSum(mat);
    cout<<min_sum<<endl;
    
    return 0;
}
