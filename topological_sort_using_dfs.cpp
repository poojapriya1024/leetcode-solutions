class Solution {
    
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& stck)
    {
       visited[node] = true;
       
       //explore it's neighbors
       for(int neighbor : adj[node])
       {
           if(!visited[neighbor])
                dfs(neighbor,adj,visited,stck);
       }
       
       //once exploration is done, add to stack
       stck.push(node);
    }
    
    void makeAdjList(vector<vector<int>>& edges, vector<vector<int>>& adj)
    {
        for(vector<int> edge : edges)
            adj[edge[0]].push_back(edge[1]);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        makeAdjList(edges, adj);
        
        stack<int> stck;
        vector<bool> visited(V, false);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,adj,visited,stck);
        }
        
        vector<int> solution;
        
        while(!stck.empty())
        {
            solution.push_back(stck.top());
            stck.pop();
        }
        
        return solution;
        
    }
};
