class Solution {
private:
    int n;
    vector<int> getPoint(int idx, vector<vector<int>>& points)
    {
        return points[idx];
    }

    void makeAdjList(vector<vector<int>>& points, vector<vector<pair<int,int>>>& adj)
    {
        //create an edge between every possible path between two points
        for(int i=0;i<n-1;i++)
        {
            //first set of points
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1;j<n;j++)
            {
                //next set of points
                int x2 = points[j][0], y2 = points[j][1];
                //find manhattan distance between them
                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});

            }
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        //1. assume each point as a node and dis between 
        // two points -> nodes and dist = weight

        n = points.size();
        vector<vector<pair<int,int>>> adj(n);

        //2. get the list of all edges
        makeAdjList(points,adj);
        vector<bool> visited(n, false);

        //3. min heap for getting minimum cost
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); // dist, idx of the point

        int minCost = 0;
        while(!pq.empty())
        {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(visited[u])
                continue;
            
            visited[u] = true;
            minCost += w;
        
            //explore the neighbours
            for(auto& [dist, v] : adj[u])
            {
                if(!visited[v])
                    pq.push({dist, v});
            }

        }

        return minCost;

    }
};
