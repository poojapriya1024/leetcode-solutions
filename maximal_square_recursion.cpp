#include<bits/stdc++.h>
using namespace std;

int n, m;
bool isValid(int x, int y)
{
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int dfs(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& dp)
{
    if(!isValid(x, y)) return 0;
    if(mat[x][y] == 0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    
    int right = dfs(x, y+1, mat, dp);
    int diag = dfs(x+1, y+1, mat, dp);
    int down = dfs(x+1, y, mat, dp);
    
    dp[x][y] = 1 + min({right, diag, down});
    return dp[x][y];
    
}
int main()
{
    vector<vector<int>> arr = {{1,1,1,0}, {1,1,1,0}, {1,1,1,1}};
    n = arr.size();
    m = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int dummy = dfs(0,0,arr,dp);
    
    int sol = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            sol = max(sol, dp[i][j]);
    }
    cout<<sol;
    
    return 0;
}
