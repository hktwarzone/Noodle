/*
Given a nested list of positive integers: {{1,1},2,{1,1}}

Compute the reverse depth sum of a nested list meaning the reverse depth of
each node (ie, 1 for leafs, 2 for parents of leafs, 3 for parents of parents
of leafs, etc.) times the value of that node.
For example:

{{1,1},2,{1,1}}
=> 1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8.

{1,{4,{6}}}
=> 6*1 + 4*2 + 1*3 = 6+8+3 = 17
*/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    vector<Node> children;
    Node(int x): value(x) {}
    Node(vector<Node> c): children(c) {}
};

class Solution {
public:
    int WeightSum(vector<Node>& lis, int level) {
        int res = 0;
        for (auto it = lis.begin(); it != lis.end(); it++) {
            if (it->children.empty()) {
                res += it->value * level;
            }
            else {
                res += WeightSum(it->children, level - 1);
            }
        }
        return res;
    }
    int Depth(vector<Node>& lis) {
        if (lis.empty()) return 0;
        int res = 0;
        for (auto it = lis.begin(); it != lis.end(); it++) {
            if (!it->children.empty()) {
                res = max(res, Depth(it->children));
            }
        }
        return res + 1;
    }
};

int main() {
    /*
    test1
    Node n1(1);
    Node n2(1);
    Node n3(2);
    Node n4(1);
    Node n5(1);
    vector<Node> p1 = {n1, n2};
    vector<Node> p2 = {n4, n5};
    vector<Node> lis = {p1, n3, p2};
    */

    Node n1(1);
    Node n2(4);
    Node n3(6);
    vector<Node> p3 = {n3};
    vector<Node> p2 = {n2, p3};
    vector<Node> lis = {n1, p2};
    Solution s;
    cout << s.WeightSum(lis, s.Depth(lis)) << endl;
    return 0;
}
