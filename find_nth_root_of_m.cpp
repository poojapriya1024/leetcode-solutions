class Solution {
  public:
    int nthRoot(int n, int m) {
        
        if(m == 0 || m == 1)
            return m;
            
        int l = 1, r = m;
        
        while(l <= r)
        {
            // (l + r)/2 causes overflow
            long long mid = l + (r - l)/2;
            long long p = pow(mid, n);
            
            if(p == m)
                return mid;
            else if(p > m)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return -1;
        
    }
};
