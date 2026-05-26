#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
        // arr = new int[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void DFShelper(int u, vector<bool> &visited){
        cout << u << " ";
        visited[u] = true;

        for(int v : l[u]){
            if(!visited[v]){
                DFShelper(v, visited);
            }
        }
    }

    void DFS(){
        vector<bool> visited(V, false);
        DFShelper(0, visited);
    }
};
int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.DFS();
    return 0;
}