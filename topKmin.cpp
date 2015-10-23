/*
a list contains n points<x, y>
given a center point and k, output top k closest points to the center
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int x;
    int y;
    int d;
    Node(int a, int b) : x(a), y(b) {}
};

class CompareNode{
public:
    bool operator()(Node& a, Node& b) {
        return a.d > b.d;
    }
};

class Solution{
public:
    vector<Node> minK(vector<Node>& v, Node& center, int k) {
        priority_queue<Node, vector<Node>, CompareNode> pq;
        for (int i = 0; i < v.size(); i++) {
            v[i].d = (v[i].x - center.x) * (v[i].x - center.x) + (v[i].y - center.y) * (v[i].y - center.y);
            pq.push(v[i]);
        }
        vector<Node> res;
        while(!pq.empty() && res.size() < k) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main() {
	// your code goes here
    Node n1(0, 0);
    Node n2(0, 1);
    Node n3(0, 2);
    Node n4(5, 5);
    vector<Node> input = {n1, n2, n3, n4};
    Solution s;
    Node center(4, 4);
    vector<Node> res = s.minK(input, center, 2);
    for (int i = 0; i < res.size(); i++) {
        cout << "(" << res[i].x << ", " << res[i].y << ")" << endl;
    }
	return 0;
}
