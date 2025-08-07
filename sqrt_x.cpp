class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0)
            return 0;

        int l = 1, r = x;

        while(l <= r)
        {
            long long m = l + (r - l)/2;

            if(m * m <= x) //search for maximum value
                l = m + 1;
            else //greater than x -> search in left half
                r = m - 1;
        }

        return r;
    }
};
