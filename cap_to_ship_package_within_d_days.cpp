class Solution {
bool canShip(vector<int>& w, int days, int cap)
{
    int currSum = 0, currDays = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] > cap) return false;
        if (currSum + w[i] <= cap)
            currSum += w[i];
        else {
            currDays++;
            currSum = w[i];
        }
    }
    currDays++; // count the last day
    return currDays <= days;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int maxCap = 0;

        for(int i=0;i<n;i++)
            maxCap += weights[i];

        int l = *max_element(weights.begin(), weights.end());
        int r = maxCap;

        while(l < r)
        {
            int mid = l + (r - l)/2;
            bool flag = canShip(weights, days, mid);

            if(flag) //try to find a minimum cap
                r = mid;
            else //increase cap to ship within d days
                l = mid + 1;
        }

        return l;

    }
};
