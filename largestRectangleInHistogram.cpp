class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        if (n == 1)
            return heights[0];
                    
        int maxArea = 0;
        stack<pair<int,int>> stck;

        for(int i=0;i<n;i++)
        {
            int start = i;

            while(!stck.empty() && heights[i] < stck.top().second)
            {
                int height = stck.top().second;
                int index = stck.top().first;
                int width = i - index;
                stck.pop(); //pop the top most element

                maxArea = max(maxArea, height * width);
                start = index; //start considering the rectangle from index
            }

            //else, push to stack
            stck.push(make_pair(start,heights[i]));
        }

        //if any more elements are left in stack, it means more rectangles can be formed
        while(!stck.empty())
        {
            int width = n - stck.top().first;
            int height = stck.top().second;
			stck.pop();

            maxArea = max(maxArea, height*width);
        }

        return maxArea;
    }
};
