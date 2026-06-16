#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adj;
    int V;
    int time;
    vector<int> dt, low;
    set<int> cp;

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parU)
    {
        int children = 0;
        dt[u] = low[u] = ++time;

        for (int v : adj[u])
        {
            if (dt[v] == -1)
            {
                children++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (parU != -1 && low[v] >= dt[u])
                    cp.insert(u);
            }
            else if (v != parU)
                low[u] = min(low[u], dt[v]);
        }

        if (parU == -1 && children > 1)
            cp.insert(u);
    }

    int articulationPoints()
    {
        time = 0;
        dt.resize(V, -1);
        low.resize(V);

        for (int i = 0; i < V; i++)
        {
            if (dt[i] == -1)
                dfs(i, -1);
        }

        for (int val : cp)
            cout << val << " ";
        cout << endl;

        return cp.size();
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(4, 3);
    graph.addEdge(4, 5);
    graph.addEdge(4, 1);

    cout << graph.articulationPoints() << endl;

    return 0;
}