class Solution {
  private:
    int n;
    bool canPlace(int dist, int cows, vector<int>& stalls)
    {
        int last = stalls[0];
        cows--;
        
        for(int i=1;i<n;i++)
        {
            int curr = stalls[i];
            if(curr - last >= dist)
            {
                last = curr;
                cows--;
            }
            
            if(cows == 0)
                return true;
        }
        
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        
        n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int l = 1, r = stalls[n-1] - stalls[0];
        
        //find the max possible difference among the cows
        while(l <= r)
        {
            int m = l + (r - l)/2;
            
            //if possible to place, find a bigger value
            if(canPlace(m,k,stalls))
                l = m + 1;
            else
                r = m - 1;
        }
        
        return r;
        
    }
};
