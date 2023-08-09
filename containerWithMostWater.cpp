#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxArea(vector<int>& height) {

    /*optimal approach
      Time Complexity = O(n)
    */
        if(height.size() == 2)
            return min(height[0],height[1]);

        int l = 0;
        int r = height.size() - 1;

        int breadth, length;
        int area = 0, curr;
        while(l < r)
        {
            breadth = r - l;
            length = min(height[l],height[r]);
            curr = length * breadth;
            cout<<"length is "<<length<<" and breadth is "<<breadth<<" so max area is "<<curr<<endl;

            if(area < curr)
                area = curr;

            if(height[l] > height[r])
            //if left height is greater than right height, move the right pointer
                r--;
            else
                l++;
            
                
        }

    return area;

}

int findMaxArea(vector<int> &height)
{
    /*brute force approach
      Time Complexity = O(n^2)
    */
    if(height.size() == 2)
            return min(height[0],height[1]);
        
    int maxArea = 0, currArea;
    for(int l=0;l<height.size();l++)
    {   
        int breadth,length;
        for(int r = l+1;r<height.size();r++)
        {
            breadth = r - l;
            length = min(height[l],height[r]);

            currArea = breadth * length;
            cout<<"length is "<<length<<" and breadth is "<<breadth<<" so max area is "<<currArea<<endl;

            if(maxArea < currArea)
                maxArea = currArea;

        }
    }

    return maxArea;
}
int main()
{
    
    vector<int> nums = {1,8,6,2,5,4,8}; //max area = 40
    int area = maxArea(nums);
    int area1 = findMaxArea(nums);

    cout<<"Through brute force approach, max area is "<<area<<endl;
    cout<<"Through optimal approach,max area is " <<area1;
    return 0;
}