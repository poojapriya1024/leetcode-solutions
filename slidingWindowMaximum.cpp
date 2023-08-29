#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{   
    int n = nums.size();
    vector<int> solution;

    if(n == 1)
    {
        solution.push_back(nums[0]);
        return solution;
    }

    //initialize a dequeue which stores the indices 
    deque<int> q;   // this is will be used as a monotonically decreasing queue

    int start = 0, end = 0;
    for(int i=0;i<n;i++)
    {   
        //pop from back all the elements which are greater than nums[i]
        while(!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();

        q.push_back(i);

        if(start > q.front())
            q.pop_front();

        if(end >= k - 1)
        {
            // add the left most element to the solution vector
            solution.push_back(nums[q.front()]);
            start++; //move to next sub-array
        }

        end++;
    }

    return solution;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> solution = maxSlidingWindow(nums,3);

    for(auto & el: solution)
        cout<<el<<" ";

    return 0;

}