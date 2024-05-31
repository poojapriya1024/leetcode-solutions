class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int len = tasks.size();
        if(len == 1)
            return 1;

        //to get the frequency or cycles of various tasks
        unordered_map<char,int> freq;

        //to store different cycles of tasks along with their start time with interval = n
        queue<pair<int,int>> q;

        //max heap to make sure the most frequent tasks are completely as early as possible - they result  
        //in more idle times and we can execute other tasks during this time
        priority_queue<int> maxHeap;

        for(char task:tasks)
            freq[task]++;

        for(auto& entry: freq)
            maxHeap.push(entry.second); //push the frequency
        
        int time = 0; //total time to execute all tasks optimally

        while(!q.empty() || !maxHeap.empty())
        {
            if(!q.empty() && q.front().second <= time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }

            if(!maxHeap.empty())
            {
                int cycles_left = maxHeap.top() - 1;
                maxHeap.pop();
                
                if(cycles_left > 0)
                    q.push({cycles_left, time+1+n}); //atleast n intervals between same tasks
            }

            time++;
        }

        return time;
    }
};
