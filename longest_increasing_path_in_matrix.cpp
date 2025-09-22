#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mat = {{3,1,2},{9,5,6},{4,8,7}};
vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
int n;

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int dfs(int i, int j, vector<vector<int>>& memo)
{
    
    if(memo[i][j] != -1)
        return memo[i][j];
    
    int currLen = 1; //starting from this cell
    for(int x=0;x<4;x++)
    {
        int xi = dir[x].first + i;
        int yi = dir[x].second + j;
        
        if(isValid(xi, yi) && mat[xi][yi] == mat[i][j] + 1)
            currLen = max(currLen, 1 + dfs(xi,yi, memo));
    }
    
    return memo[i][j] = currLen;
    
}
int main()
{
    n = mat.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    
    int sol = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp = dfs(i, j, memo);
            sol = max(sol,temp);
        }
    }
    
    cout<<sol;
    return 0;
}
