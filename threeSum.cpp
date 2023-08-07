#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;


// vector<vector<int>> threeSum(vector<int>& nums) 
// {
//         vector<vector<int>> result;

//         if(nums.size() == 3)
//         {
//             if(nums[0] + nums[1] + nums[2] == 0)
//                 result.push_back(nums);

//             return result;
//         }

//         //declare a map
//         unordered_map<int,int> myMap;
//         unordered_set<int> set;
        
//         sort(nums.begin(),nums.end());
//         for(auto &num : nums)
//             set.insert(num);


//         for(int i=0;i<nums.size();i++)
//         {   
//             if(i>0 && nums[i] == nums[i-1])
//                 continue;
                
//             int el = nums[i];
//             if(set.find(0) != set.end() && set.find(0-el) != set.end()) //if zero is present and the negative number is present
//             {
//                 vector<int> solution;
//                 solution.push_back(el);
//                 solution.push_back(0);
//                 solution.push_back(0-el);

//                 //check for duplicates before inserting
//                 result.push_back(solution);
//             }

//             else
//             {
//                 //find two numbers whose sum is equal to 0-el using a 2 pointer approach

//                 int l =  0;
//                 int r = nums.size() - 1;

//                 while(l < r)
//                 {
//                     if(nums[l] + nums[r] == (0 - el))
//                     {
//                         vector<int> solution;
//                         solution.push_back(el);
//                         solution.push_back(nums[l]);
//                         solution.push_back(nums[r]);

//                         //check for duplicates before inserting
//                         result.push_back(solution);
//                     }

//                     else if (nums[l] + nums[r] > (0 - el))
//                         r--;
                    
//                     else
//                         l++;
//                 }
//             }

//         }
        
//         return result;


// }

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;

        if(nums.size() == 3)
        {
            if(nums[0] + nums[1] + nums[3] == 0)
                solution.push_back(nums);

            return solution;
        }


        //sort the nums array

        sort(nums.begin(),nums.end());

        for (int i=0;i<nums.size();i++)
        {
            if(i > 0 - 1 && nums[i] == nums[i-1])
                //if duplicate elements are present
                continue;

                int l = i+1;
                int r = nums.size() - 1;

                while(l < r)
                {
                    int threeSum = nums[i] + nums[l] + nums[r];

                    if(threeSum > 0)
                        r--;
                    else if (threeSum < 0)
                        l++;
                    else
                    {
                        //append the three values
                        vector<int> result;
                        result.push_back(nums[i]);
                        result.push_back(nums[l]);
                        result.push_back(nums[r]);
                        solution.push_back(result);

                        //checking for duplicates
                        while (l < r && nums[l] == nums[l+1]) //left duplicate
                            l++;
                        while (l < r && nums[r] == nums[r-1]) //right duplicate
                            r--;

                        l++;
                        r--;

                    }
                }
        }
        
        return solution;
}
int main()
{
    vector<int> nums = {0,0,0,3};
    vector<vector<int>> answer = threeSum(nums);

    for(int i=0;i<answer.size();i++)
    {
        for(int j=0;j<answer[i].size();j++)
            cout<<answer[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}