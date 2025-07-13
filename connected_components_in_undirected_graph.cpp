
class Solution {
  private:
    vector<int> rank, parent;
    
    void init(int v)
    {
        rank.resize(v);
        parent.resize(v);
        
        for(int i=0;i<v;i++)
        {
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int findParent(int x)
    {
        if(parent[x] == x)
            return x;
        
        return parent[x] = findParent(parent[x]);
    }
    
    void unionOp(int x, int y)
    {
        int parent_x = findParent(x);
        int parent_y = findParent(y);
        
        if(parent_x != parent_y)
        {
            if(rank[parent_x] > rank[parent_y])
                parent[parent_y] = parent_x;
            else if (rank[parent_y] > rank[parent_x])
                parent[parent_x] = parent_y;
            else
            {
                parent[parent_x] = parent_y;
                rank[parent_y]++;
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        init(V);
        
        for(vector<int> edge : edges)
        {
            int u = edge[0], v = edge[1];
            unionOp(u,v);
        }
        
        unordered_map<int, vector<int>> mp;
        
        for(int i=0;i<V;i++)
        {
            // (key - parent, val - index(node))
            int key = findParent(i);
            mp[key].push_back(i);
        }
        
        vector<vector<int>> solution;
        
        for(auto entry: mp)
            solution.push_back(entry.second);
            
        return solution;
        
    }
};
