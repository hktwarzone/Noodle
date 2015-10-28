#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int v): val(v) {}
};

class Solution {
public:
    bool isBipartite(vector<Node*>& graph) {
        if (graph.empty()) return true;
        map<Node*, int> m;
        queue<Node*> q;
        m[graph[0]] = 1;
        q.push(graph[0]);
        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            for (int i = 0; i < n->neighbors.size(); i++) {
                if (m.find(n->neighbors[i]) != m.end()) {
                    if (m[n->neighbors[i]] != -m[n]) return false;
                }
                else {
                    m[n->neighbors[i]] = -m[n];
                    q.push(n->neighbors[i]);
                }
            }
        }
        return true;
    }
};

int main() {
	// your code goes here
	Node a(1);
	Node b(2);
	Node c(3);
	Node d(4);
	a.neighbors = {&b, &d};
	b.neighbors = {&a, &c};
	c.neighbors = {&b, &d};
	d.neighbors = {&a, &c};
	vector<Node*> input = {&a, &b, &c, &d};
	Solution s;
	cout << s.isBipartite(input) << endl;
	Node e(5);
	Node f(6);
	Node g(7);
	e.neighbors = {&f, &g};
	f.neighbors = {&e, &g};
	g.neighbors = {&e, &f};
	vector<Node*> input2 = {&e, &f, &g};
	cout << s.isBipartite(input2) << endl;
	return 0;
}
