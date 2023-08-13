#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        if (n == 1)
            return 0;

        vector<int> leftSum(n);
        vector<int> rightSum(n);

        leftSum[0] = 0;
        for(int i=1;i<n;i++)
            leftSum[i] = leftSum[i-1] + nums[i-1];

        rightSum[n-1] = 0;
        for(int j=n-2;j>=0;j--)
            rightSum[j] = rightSum[j+1] + nums[j+1];

        for(int k=0;k<n;k++)
        {
            if(leftSum[k] == rightSum[k])
                return k; //return the index
        }
        
        return -1;
}

int main()
{
    vector<int> num1 = {1,7,3,6,5,6}; //pivotIndex = 3
    vector<int> num2 = {2,1,-1}; //pivotIndex = 0;

    int res1 = pivotIndex(num1);
    cout<<"Pivot Index for num1 is "<<res1<<endl;
    int res2 = pivotIndex(num2);
    cout<<"Pivot Index for num2 is "<<res2<<endl;
    return 0;
}