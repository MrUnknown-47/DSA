class Solution {
public:

    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& path, vector<vector<int>>& edges) {
        vis[src] = true;
        path[src] = true;

        for (int i =0 ;i< edges.size(); i++) {
            int v= edges[i][0];
            int u= edges[i][1];
            if(u == src){
                if (!vis[v]) {
                if (dfs(v, vis, path, edges))
                    return true;
                }

                else if (path[v]) {
                    return true;
                }
            }
            
        }

        path[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, edges))
                    return false;
            }
        }

        return true;
    }
};