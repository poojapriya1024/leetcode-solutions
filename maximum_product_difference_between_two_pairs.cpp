class Solution {
private:
    int partition(vector<int>& nums,int start,int end)
    {   
        //set last element as the pivot element
        int pivot = nums[end];
        int x = -1;

        for(int i=0;i<end;i++)
        {
            if(nums[i] < pivot)
            {
                x++;
                swap(nums[i],nums[x]);
            }
        }

        //now the correct index for pivot is given by index = x+1
        swap(nums[x+1],nums[end]);
        return x+1;

    }
    void quicksort(vector<int>& nums,int start,int end)
    {
        if(start > end)
            return;
        
        int partition_index = partition(nums,start,end);
        quicksort(nums,start,partition_index-1);
        quicksort(nums,partition_index+1,end);

    }
public:
    int maxProductDifference(vector<int>& nums) {
        
        int len = nums.size();
        //sort the input array
        sort(nums.begin(),nums.end());
        //solution = difference between the pdt of first two elements and last two elements

        int min_pdt = nums[0]*nums[1];
        int max_pdt = nums[len-2]*nums[len-1];

        return (max_pdt - min_pdt);

    }
};
