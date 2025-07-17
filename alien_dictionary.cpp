class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        int n = words.size();
        
        unordered_map<char, vector<char>> adj;
        set<char> alpha;
        vector<int> indegree(26,0);
        
        // 1. get all the unique alphabets
        for(auto& word : words)
        {
            for(char ch : word)
                alpha.insert(ch);
        }
        
        //2. build the graph and indegree array by comparing adjacent words 
        for(int i=0;i<n-1;i++)
        {
            //compare the adjacent words to find which character comes first
            string word1 = words[i], word2 = words[i+1];
            int len = min(word1.length(), word2.length());
            bool flag = false;
            
            for(int j=0;j<len;j++)
            {
                if(word1[j] != word2[j])
                {
                    flag = true;
                    adj[word1[j]].push_back(word2[j]);
                    indegree[word2[j] - 'a']++;
                    break;
                }
                
            }
            
            
            if(!flag && word1.length() > word2.length())
                    return "";
        }
        
        //make the indegree array from the adj
        int v = alpha.size();
        queue<char> q;
        
        for(char ch : alpha)
        {
            if(indegree[ch - 'a'] == 0)
                q.push(ch);
        }
        
        string solution = "";
        
        while(!q.empty())
        {
            char curr = q.front();
            int idx = curr - 'a';
            q.pop();
            
            solution += curr;
            
            for(char ch : adj[curr])
            {
                indegree[ch - 'a']--;
                if(indegree[ch - 'a'] == 0)
                    q.push(ch);
            }
        }
        
        if(solution.length() != v) return ""; //loop
        return solution;
        
        
        
    }
};
