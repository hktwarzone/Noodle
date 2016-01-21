#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(int n): V(n) {
        adj = vector<vector<int>>(n, vector<int>());
    }
    void addEdge(int u, int w) {
        if (u >= 0 && u < V && w >= 0 && w < V) adj[u].push_back(w);
    }
    bool hasCycle() {
        vector<bool> ancestors(V, false);
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if(hasCycleHelper(i, visited, ancestors)) return true;
        }
        return false;
    }
private:
    int V;
    vector<vector<int>> adj;
    bool hasCycleHelper(int i, vector<bool>& visited, vector<bool>& ancestors) {
        if (!visited[i]) {
            visited[i] = true;
            ancestors[i] = true;
            for (int j = 0; j < adj[i].size(); j++) {
                if (!visited[adj[i][j]] && hasCycleHelper(adj[i][j], visited, ancestors)) return true;
                else if (ancestors[adj[i][j]]) return true;
            }
        }
        ancestors[i] = false;
        return false;
    }
};

int main() {
	// your code goes here
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.hasCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
	return 0;
}
