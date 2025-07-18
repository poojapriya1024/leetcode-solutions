class Solution {
private:
    vector<int> parent, rank;
public:
    void init(int n)
    {   
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findParent(int node)
    {
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionOp (int x, int y)
    {
        int parent_x = findParent(x);
        int parent_y = findParent(y);

        if(parent_x != parent_y)
        {
            //check ranks
            if(rank[parent_x] > rank[parent_y])
                parent[parent_y] = parent_x;
            else if(rank[parent_y] > rank[parent_x])
                parent[parent_x] = parent_y;
            else
            {
                parent[parent_x] = parent_y;
                rank[parent_y]++;
            }
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        init(n);

        for(vector<int> edge : edges)
        {
            if(findParent(edge[0]) == findParent(edge[1]))
                return edge;
            
            unionOp(edge[0], edge[1]);
        }

        return {};

    }
};
