class Solution {
private:
    int n;
bool canMakeBouq(vector<int>& arr, int m, int k, int day)
{ 
    //make m boques of size k
    int count = 0;
    bool prev = false;
    
    for(int i=0;i<arr.size();i++)
    {
        //cout<<"curr flower is "<<arr[i]<<endl;
        //flower is bloomed
        if(arr[i] <= day)
        {
            if(!prev) 
            {
                count = 1;
                prev = true;
            }
            else count++;
        }
        
        //flower is not bloomed
        else
        {
            count = 0;
            prev = false;
        }
        
        if(count == k)
        {
            m--;
            prev = false;
        }
        
    }
    
    return (m <= 0);
    
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        n = bloomDay.size();

        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while(l < r)
        {
            int mid = l + (r - l)/2;
            bool canMake = canMakeBouq(bloomDay,m,k,mid);

            if(canMake) //try to find a min day
                r = mid;
            else
                l = mid + 1;

        }

        return canMakeBouq(bloomDay,m,k,l) ? l : -1;
    }
};
