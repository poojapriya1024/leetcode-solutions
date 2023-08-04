#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> solution;

        if(nums.size() == 2)
        {
            copy(nums.rbegin(),nums.rend(),solution.begin());
            return solution;
        }

        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        solution.resize(n); 

        for(int i=1;i<n;i++)
        {
            //calculate the prefix product of each element
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i=n-2;i>=0;i--)
            suffix[i] = suffix[i+1] * nums[i+1];

        for(int i=0;i<n;i++)
            solution[i] = prefix[i] * suffix[i];

        return solution;

    
}

void printArray(vector<int>& nums)
{
    for(auto& ch : nums)
        cout<<ch<<" ";
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> solution = productExceptSelf(nums);
    printArray(solution);

    return 0;
}