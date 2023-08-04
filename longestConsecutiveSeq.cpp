//approach : sorting the array and finding the longest consecutive sequence 

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) 
{       
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return 1;

        //sort the array
        sort(nums.begin(),nums.end());

        // declare a variable to store the maximum length 
        int max = 0,curr=1;

        for(int i=1;i<nums.size();i++)
        {

            if(nums[i] == nums[i-1])
                continue;

            if(nums[i] - 1 == nums[i-1]) 
                curr++;

            else
            { 
                if(max < curr)
                    max = curr;

                curr = 1;
            }
            
        }

         if(max < curr)
                    max = curr;

        return max;

}

int main()
{
    vector<int> nums = {150,300,100,501,503,502,608};
    int res = longestConsecutive(nums);
    cout<<res;
    return 0;
}