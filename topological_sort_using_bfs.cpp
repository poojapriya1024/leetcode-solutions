class Solution {
  private:
    void makeAdjList(vector<vector<int>>& edges, vector<vector<int>>& adj, vector<int>& indeg)
    {
        for(vector<int> edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);
        
        makeAdjList(edges, adj,indeg);
        
        queue<int> q;
    
        for(int i=0;i<V;i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
                
        }
        
        vector<int> solution;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            solution.push_back(curr);
            
            //explore it's neighbours and remove the indegree for each
            for(int neighbour : adj[curr])
            {
                indeg[neighbour]--;
                
                if(indeg[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        
        return solution;
    }
};
