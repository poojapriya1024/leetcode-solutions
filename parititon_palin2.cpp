class Solution {
private:
    bool isPalidrome(int l, int r, string word)
    {
        while(l <= r)
        {
            if(word[l] != word[r]) return false;
            l++;
            r--;
        }

        return true;
    }

public:
    int minCut(string s) {
        
        int n = s.length();
        vector<int> dp(n+1, 0);

        for(int i=n-1;i>=0;i--)
        {
            int minPart = INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPalidrome(i, j, s))
                    minPart = min(minPart, 1 + dp[j+1]);
            }

            dp[i] = minPart;
        }

        return dp[0]-1;
    }
};
