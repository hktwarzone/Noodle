//http://www.geeksforgeeks.org/avl-tree-set-1-insertion/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): value(v) {
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class AVLTree {
public:
    TreeNode* root;
    AVLTree() {
        root = NULL;
    }
    int height(TreeNode* root) {
        return (root) ? root->height : 0;
    }
    int balance(TreeNode* root) {
        return (root) ? height(root->left) - height(root->right) : 0;
    }
    TreeNode* rotateLeft(TreeNode* root) {
        TreeNode* child = root->left;
        if (!child) return root;
        TreeNode* gchild = child->right;
        child->right = root;
        root->left = gchild;
        root->height = max(height(root->left), height(root->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;
        return child;
    }
    TreeNode* rotateRight(TreeNode* root) {
        TreeNode* child = root->right;
        if (!child) return root;
        TreeNode* gchild = child->left;
        child->left = root;
        root->right = gchild;
        root->height = max(height(root->left), height(root->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;
        return child;
    }
    TreeNode* addNodeUtil(TreeNode* root, int v) {
        if (!root) {
            return new TreeNode(v);
        }
        if (v < root->value) {
            root->left = addNodeUtil(root->left, v);
        }
        else {
            root->right = addNodeUtil(root->right, v);
        }
        root->height = max(height(root->left), height(root->right)) + 1;
        
        int bal = balance(root);
        if (bal > 1 && v < root->left->value)
            return rotateRight(root);
 
        if (bal < -1 && v > root->right->value)
            return rotateLeft(root);
 
        if (bal > 1 && v > root->left->value)
        {
            root->left =  rotateLeft(root->left);
            return rotateRight(root);
        }

        if (bal < -1 && v < root->right->value)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
/*
        if (balance(root) > 1) {
            if (v > root->left->value) {
                root->left = rotateLeft(root->left);
            }
            return rotateRight(root);
        }
        else if (balance(root) < -1) {
            if (v < root->right->value) {
                root->right = rotateRight(root->right);
            }
            return rotateLeft(root);
        }
*/
        return root;
    }
    void addNode(int v) {
        root = addNodeUtil(root, v);
    }
};

void preOrder(TreeNode* root)
{
    if(root)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
	// your code goes here
	AVLTree t;
	t.addNode(10);
	t.addNode(20);
	t.addNode(30);
	t.addNode(40);
	t.addNode(50);
	t.addNode(25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  cout << "Pre order traversal of the constructed AVL tree is " << endl;
  preOrder(t.root);
  return 0;
}
