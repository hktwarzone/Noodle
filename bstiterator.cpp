#include <iostream>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int v): value(v) {
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class BSTIterator {
public:
    TreeNode* curr;
    BSTIterator(TreeNode* start) {
        if (!start) return;
        curr = start;
    }
    BSTIterator& operator++(int) {
        if (!curr) return *this;
        if (curr->right) {
            TreeNode* next = curr->right;
            while(next->left) { next = next->left; }
            curr = next;
        }
        else {
            TreeNode* child = curr;
            TreeNode* next = curr->parent;
            while(next && next->right == child) {
                child = next;
                next = next->parent;
            }
            curr = next;
        }
        return *this;
    }
    int& operator*() {
        return curr->value;
    }
    bool operator==(const BSTIterator& right) const {
        return curr == right.curr;
    }
    BSTIterator& operator=(const BSTIterator& right) {
        curr = right.curr;
        return *this;
    }
};

class Tree {
public:
    TreeNode* root;
    Tree() {
        root = NULL;
    }
    void addNode(int v) {
        if (!root) {
            root = new TreeNode(v);
            return;
        }
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while(curr) {
            if (curr->value == v) return;
            else if (curr->value < v) {
                prev = curr;
                curr = curr->right;
            }
            else {
                prev = curr;
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
        TreeNode* curr = root;
        while(curr->left) { curr = curr->left; }
        return BSTIterator(curr);
    }
    BSTIterator end() {
        TreeNode* curr = root;
        while(curr->right) { curr = curr->right; }
        return BSTIterator(curr);
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
	BSTIterator it = BSTtree.begin();
	while (1) {
	    if (it == BSTtree.end()) break;
    	cout << *it << endl;
	    it++;
	}
	cout << *it << endl;
	return 0;
}
