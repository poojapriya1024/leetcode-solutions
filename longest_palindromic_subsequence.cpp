#include<bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string x, string y)
{
    int xlen = x.length(), ylen = y.length();
    vector<vector<int>> dp(xlen+1, vector<int>(ylen+1,0));
    
    for(int i=1;i<=xlen;i++)
    {
        for(int j=1;j<=ylen;j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    
    string solution = "";
    int i = xlen, j = ylen;
    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            solution = x[i-1] + solution;
            i--;
            j--;
        }
        else {
            
            if(dp[i-1][j] > dp[i][j-1]) //move up
                i--;
            else
                j--;
        }
    }
    cout<<"Longest common subsequence is "<<solution<<" and its length is "<<solution.length();
    return solution.length();
}
int main() {
    string y = "ddeefighieeddhi"; //ddeeigieedd
    string x = y;
    reverse(x.begin(), x.end());
    int solution = longestPalindromicSubsequence(x,y);
    return 0;
}
