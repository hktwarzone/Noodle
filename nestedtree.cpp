/*
Construct tree from {A{B{C}{D}}{E}{F}}
to become
   A
 / \ \
 B  E F
/ \
C  D
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
    string s;
    vector<TreeNode*> children;
    TreeNode(string ss): s(ss) {}
};

class Solution {
public:
    TreeNode* parse(string s) {
        int start = 0;
        return parseHelper(s, start);
    }
private:
    TreeNode* parseHelper(string& s, int& start) {
        start++;
        string tmp;
        while(s[start] != '{' && s[start] != '}') {
            tmp += s[start++];
        }
        TreeNode* curr = new TreeNode(tmp);
        while (s[start] == '{') {
            curr->children.push_back(parseHelper(s, start));
        }
        start++;
        return curr;
    }
};

int main() {
	// your code goes here
	string input = "{A{B{C}{D}}{E}{F}}";
	Solution s;
	TreeNode* root = s.parse(input);
	queue<TreeNode*> q, next;
	q.push(root);
	while(!q.empty()) {
	    while(!q.empty()) {
	        TreeNode* n = q.front();
	        q.pop();
	        cout << n->s << "'s children : ";
	        if (n->children.empty()) cout << "none";
	        for (int i = 0; i < n->children.size(); i++) {
	            next.push(n->children[i]);
	            cout << n->children[i]->s << " ";
	        }
	        cout << endl;
	    }
	    swap(q, next);
	}
	return 0;
}
