class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = flowers.size();
        vector<int> starts;
        vector<int> ends;

        for(int i=0;i<n;i++) {
            starts.push_back(flowers[i][0]);
            ends.push_back(flowers[i][1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> solution;
        for(auto &p: people) {
           const int started = upper_bound(starts.begin(), starts.end(), p) - starts.begin();
           const int ended = lower_bound(ends.begin(), ends.end(), p) - ends.begin();
           solution.push_back(started - ended);
        }

        return solution;
    }
};
