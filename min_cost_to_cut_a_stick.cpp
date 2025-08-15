#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
{
    //length of the current cuts
    int currLen = j - i;
    if(currLen == 1)
        return 0; //any more cuts are not possible
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    //find all possible cuts within this range (i,j)
    int minCost = INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        int cost = cuts[j] - cuts[i];
        int left = solve(i,k,cuts, dp);
        int right = solve(k,j, cuts, dp);
        
        minCost = min(minCost,
                        cost + left + right);
    }
    
    return dp[i][j] = (minCost == INT_MAX ? 0 : minCost);
}

int solveTabulation(vector<int>& cuts)
{
    int n = cuts.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int len=2;len<n;len++)
    {
        for(int i=0;i+len<n;i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                int cost = cuts[j] - cuts[i];
                dp[i][j] = min(dp[i][j], 
                                cost + dp[i][k] + dp[k][j]);
                
            }
        }
    }
    
    return dp[0][n - 1];
}
int main()
{
    vector<int> cuts = {1,4};
    int len = 6;
    
    cuts.push_back(len);
    cuts.push_back(0);
    int n = cuts.size();
    
    sort(cuts.begin(), cuts.end());
    
    
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // int solution = solve(0,cuts.size()-1, cuts, dp);
    // cout<<solution;
    
    int solution = solveTabulation(cuts);
    cout<<solution;
    
    return 0;
}
