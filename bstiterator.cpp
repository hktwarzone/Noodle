#include <iostream>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int v): value(v) { left = NULL; right = NULL; parent = NULL; }
};

class BSTIterator {
public:
    TreeNode* ptr;
    BSTIterator(TreeNode* p): ptr(p) {}
    BSTIterator& operator++(int) {
        if (ptr && ptr->right) {
            TreeNode* next = ptr->right;
            while(next->left) { next = next->left; }
            ptr = next;
        }
        else if (ptr) {
            TreeNode* child = ptr;
            TreeNode* next = ptr->parent;
            while(next && next->right == child) {
                child = next;
                next = next->parent;
            }
            ptr = next;
        }
        return *this;
    }
    int& operator*() { return ptr->value; }
    bool operator==(const BSTIterator& right) const { return ptr == right.ptr; }
    bool operator!=(const BSTIterator& right) const { return ptr != right.ptr; }
};

class Tree {
public:
    TreeNode* root;
    Tree() { root = NULL; }
    void addNode(int v) {
        if (!root) {
            root = new TreeNode(v);
            return;
        }
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while(curr) {
            prev = curr;
            if (curr->value == v) return;
            else if (curr->value < v) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        if (prev->value < v) { 
            prev->right = new TreeNode(v);
            prev->right->parent = prev;
        }
        else {
            prev->left = new TreeNode(v);
            prev->left->parent = prev;
        }
    }
    BSTIterator begin() {
        if (!root) return BSTIterator(NULL);
        TreeNode* curr = root;
        while(curr->left) { curr = curr->left; }
        return BSTIterator(curr);
    }
    BSTIterator end() {
        return BSTIterator(NULL);
    }
};

int main() {
	Tree BSTtree;
	BSTtree.addNode(32);
	BSTtree.addNode(16);
	BSTtree.addNode(8);
	BSTtree.addNode(24);
	BSTtree.addNode(48);
	BSTtree.addNode(56);
	for (BSTIterator it = BSTtree.begin(); it != BSTtree.end(); it++) {
    	cout << *it << endl;
	}
	return 0;
}
