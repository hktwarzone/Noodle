#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    int count;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int i): val(i) { count = 0; }
};

class Tree {
public:
    TreeNode* root;
    int size;
    Tree() { root = NULL; size = 0;}
    void insert(int x) {
        if (!root) { root = new TreeNode(x);}
        else {
            TreeNode* curr = root;
            TreeNode* newnode = new TreeNode(x);
            while(curr) {
                if (x < curr->val) {
                    if (!curr->left) {
                        curr->left = newnode;
                        break;
                    }
                    curr = curr->left;
                }
                else {
                    curr->count++;
                    if (!curr->right) {
                        curr->right = newnode;
                        break;
                    }
                    curr = curr->right;
                }
            }
        }
        size++;
    }
    int query(int rank) {
        return queryHelper(root, rank);
    }
    TreeNode* rightRotate(TreeNode* z) {
        if (!z) return z;
        TreeNode* y = z->left;
        if (!y) return z;
        TreeNode* x = y->right;
        y->right = z;
        z->left = x;
        y->count += (1 + z->count);
        return y;
    }
    TreeNode* leftRotate(TreeNode* z) {
        if (!z) return z;
        TreeNode* y = z->right;
        if (!y) return z;
        TreeNode* x = y->left;
        y->left = z;
        z->right = x;
        z->count -= (1 + y->count);
        return y;
    }
private:
    int queryHelper(TreeNode* root, int rank) {
        int larger_count = 0;
        TreeNode* curr = root;
        while(curr) {
            if (rank == larger_count + curr->count + 1) {
                return curr->val;
            }
            else if (rank < larger_count + curr->count + 1) {
                curr = curr->right;
            }
            else {
                larger_count += curr->count + 1;
                curr = curr->left;
            }
        }
        return -1;
    }
};

int main() {
	// your code goes here
	Tree t;
	t.insert(10);
	t.insert(9);
	t.insert(8);
	t.insert(7);
	t.insert(6);
	t.insert(5);
	t.insert(4);
	for (int i = 0; i < t.size; i++) {
	    cout << "t.query(" << i + 1 << ") = " << t.query(i + 1) << endl;
	}
	t.root = t.rightRotate(t.root);
	for (int i = 0; i < t.size; i++) {
	    cout << "t.query(" << i + 1 << ") = " << t.query(i + 1) << endl;
	}
	return 0;
}
