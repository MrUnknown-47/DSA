class Solution
{
public:
    int time;
    vector<int> dt, low;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;

    void dfs(int u, int parU)
    {
        dt[u] = low[u] = ++time;

        for (int v : adj[u])
        {
            if (dt[v] == -1)
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > dt[u])
                    bridges.push_back({u, v});
            }
            else if (v != parU)
                low[u] = min(low[u], dt[v]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        adj.resize(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.resize(n, -1);
        low.resize(n);

        for (int i = 0; i < n; i++)
        {
            if (dt[i] == -1)
                dfs(i, -1);
        }

        return bridges;
    }
};