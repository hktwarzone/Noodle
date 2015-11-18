#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* up;
    Node* down;
    Node* right;
    Node(int x): val(x) {
        up = NULL;
        down = NULL;
        right = NULL;
    }
};

class Solution {
public:
  Node* flatten(Node* head) {
      if (!head) return NULL;
      Node* tail = head;
      while(tail->right) {
          tail = tail->right;
      }
      Node* curr = head;
      while(curr != tail) {
          if(curr->up) {
              tail->right = curr->up;
              curr->up = NULL;
              while(tail->right) {
                  tail = tail->right;
              }
          }
          if (curr->down) {
              tail->right = curr->down;
              curr->down = NULL;
              while(tail->right) {
                  tail = tail->right;
              }
          }
          curr = curr->right;
      }
      return head;
  }  
};

int main() {
	// your code goes here
	
	Node a(1);
	Node b(2);
	Node c(3);
	Node d(4);
	Node e(5);
	Node f(6);
	Node g(7);
	Node h(8);
	Node i(9);
	Node j(10);
	Node k(11);
	Node l(12);
	
	a.up = &b;
	b.right = &c;
	c.up = &d;
	a.right = &e;
	e.down = &f;
	f.right = &g;
	g.up = &h;
	e.right = &i;
	Solution s;
	s.flatten(&a);
	for (Node* curr = &a; curr != NULL; curr = curr->right) {
	    cout << curr->val << " -> ";
	}
	cout << "NULL" << endl;
	return 0;
}
