/*brute force approach
  keep track of the maximum left height, maximum right height and then minimum of these heights. 
  then, find the possible amount of water that can be stored at any level using the formula min(lheight,rheight) - cuur_height*/ 

#include<iostream>
#include<vector>
using namespace std;


int trap(vector<int>& height) 
{   
    int n = height.size();
    int maxLeftHeight[n],LCount = 0;
    int maxRightHeight[n],RCount = 0;

    int Lmax = 0, Rmax = 0, res = 0;

    //finding the maximum left height of each level
    for(int i=0;i<n;i++)
    {
        Lmax = max(Lmax,height[i]);
        if(i == 0) 
            maxLeftHeight[i] = 0;
        else
            maxLeftHeight[i] = Lmax;
        cout<<"max left height of "<<height[i]<<" is "<<maxLeftHeight[i]<<endl;
    }

    //finding the maximum right height of each level
    for(int j=n-1;j>=0;j--)
    {  
        Rmax = max(Rmax,height[j]);
        if(j == n-1)
            maxRightHeight[j] = 0;
        else
            maxRightHeight[j] = Rmax;
        cout<<"max right height of "<<height[j]<<" is "<<maxRightHeight[j]<<endl;
    }

    for(int k=0;k<n;k++)
    {  
        if( min(maxLeftHeight[k],maxRightHeight[k]) - height[k] > 0)
         res += (min(maxLeftHeight[k],maxRightHeight[k]) - height[k]);
    }

    return res;  
}
int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; //ans : 6
    int ans = trap(height);
    cout<<"Max trapped water is "<<ans;
    return 0;
}