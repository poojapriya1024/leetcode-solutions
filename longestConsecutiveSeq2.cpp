//approach : using a set

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int max=0,curr=0;
        //initialize a set
        unordered_set<int> set;

        //copy the elements of the num into the set
        for(auto &num : nums)  
            set.insert(num);

        for(int i=0;i<nums.size();i++)
        {
            //checking if this is the start of a sequence 
            if(!set.count(nums[i]-1)) //previous consecutive element is not present
            {
                curr = 1;
                //check for next consecutive elements
                while(set.count(nums[i] + curr)) 
                    curr++;

                //compare the current length with the max length
                if(max < curr)
                    max = curr; cout<<"Max is "<<max<<" and curr is "<<curr<<endl;

            }
        }
        

    return max;        
}

int main()
{
    vector<int> nums1 = {150,300,100,501,503,502,608}; //length = 3
    vector<int> nums2 = {8,10,11,15,56,13,12,20}; //length = 4
    vector<int> nums3 = {0,0}; //length = 1
    vector<int> nums4 = {1,2}; //length = 2

    int res1 = longestConsecutive(nums1);
    int res2 = longestConsecutive(nums2);
    int res3 = longestConsecutive(nums3);
    int res4 = longestConsecutive(nums4);

    cout<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<" ";

    return 0;
}