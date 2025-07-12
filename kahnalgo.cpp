class Solution
{
    public:
    vector<int> toposort(int v,vector<int>adj[])
    {
        int indegree[v]={0};
        for(i=0;i<v;i++)
        {
            for(auto it :adj[i])
            {
                indgree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            top.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        return topo;
    }
};