class Solution
{
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &path, vector<vector<int>> &edges)
    {
        vis[src] = true;
        path[src] = true;

        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];
            if (u == src)
            {
                if (!vis[v])
                {
                    if (isCycleDFS(v, vis, path, edges))
                        return true;
                }

                else if (path[v])
                {
                    return true;
                }
            }
        }

        path[src] = false;
        return false;
    }

    void topoOrder(int curr, vector<bool> &vis, stack<int> &s, vector<vector<int>> &edges)
    {
        vis[curr] = true;

        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];
            if (u == curr)
            {
                if (!vis[v])
                    topoOrder(v, vis, s, edges);
            }
        }
        s.push(curr);
    }

    vector<int> findOrder(int n, vector<vector<int>> &edges)
    {
        vector<bool> vis(n, false);
        vector<bool> path(n, false);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (isCycleDFS(i, vis, path, edges))
                    return ans;
            }
        }

        stack<int> s;
        vis.assign(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topoOrder(i, vis, s, edges);
            }
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};