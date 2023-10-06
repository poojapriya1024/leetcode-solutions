class Solution {
private:
    int dfs(int n) {
        if(n <= 2)
            return 1;

        int maxPdt = INT_MIN;

        for(int i=1;i<n;i++)
        {   
            // max(dfs(n-i), n-i) => if breaking down n-i is lesser than itself, don't break at all
            int currPdt = i * max(dfs(n-i), n-i);
            maxPdt = max( maxPdt, currPdt);
        }

        return maxPdt;
    }
public:
    int integerBreak(int n) {
        
        return dfs(n);
    }
};
