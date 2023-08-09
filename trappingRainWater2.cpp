
//two pointer approach which finds the bottle neck b/w each left and right values
#include<iostream>
#include<vector>
using namespace std;


int trap(vector<int> &height)
{
    int n = height.size();

    if(n == 1)
        return 0;
    
    int l = 0, r = n-1,res = 0;
    int leftMax = height[l], rightMax = height[r];

    while(l < r) 
    {
        if(height[l] < height[r])
        {
            //increment the left pointer
            l++;
            //to find the amount of water that can be trapped at each level
            leftMax = max(leftMax,height[l]);
            res += (leftMax - height[l]);
        }

        else
        {
            //decrement the left pointer
            r--;
            rightMax = max(rightMax,height[r]);
            res += (rightMax - height[r]);
        }
    }

    return res;

}

int main()
{
    vector<int> height = {4,2,0,3,2,5}; //ans : 6
    int ans = trap(height);
    cout<<"Max trapped water is "<<ans;
    return 0;
}