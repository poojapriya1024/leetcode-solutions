class Solution {
  private:
    void makeAdjList(vector<vector<int>>& edges, vector<vector<int>>& adj)
    {
        for(vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
  public:
 
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        makeAdjList(edges, adj);
        
        vector<bool> visited(V, false);
        
        
        for(int i=0;i<V;i++)
        {
            if(visited[i])
                continue;
            
            queue<pair<int,int>> q;
            q.push({i,-1});
            visited[i] = true;
        
            while(!q.empty())
        {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            //explore it's neighbours
            for(int neighbour : adj[curr])
            {
                
                //if the neighbour is the parent, skip it
                //as it would have been visited already
                if(neighbour == parent)
                    continue;
                
                if(!visited[neighbour])
                {
                    q.push({neighbour,curr});
                    visited[neighbour] = true;
                } else
                    return true;
            }
        }
        }
        
        return false;
        
    }
};
