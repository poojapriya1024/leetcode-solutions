class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int len = nums.size();

        if(len == 1)
            return nums[0];

        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(int num : nums)
        {
            minHeap.push(num);
            while(minHeap.size() > k)
                minHeap.pop(); 
        }

        return minHeap.top(); //hold the kth largest element
    }
};
