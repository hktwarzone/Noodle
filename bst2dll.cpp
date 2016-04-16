// Binary Search Tree conversion to Doubly Linked List
// Note: maintain a global TreeNode* (prev) to track last "ListNode"
#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): value(v) {
        left = NULL;
        right = NULL;
    }
};

void bst2dll(TreeNode* root, TreeNode*& head, TreeNode*& prev) {
    if (!root) return;
    bst2dll(root->left, head, prev);
    if (!prev) {
        head = root;
    }
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    bst2dll(root->right, head, prev);
}

void printLL(TreeNode* head) {
    if (!head) return;
    while(head) {
        cout << head->value << " -> ";
        head = head->right;
    }
    cout << "NULL" << endl;
}


int main() {
    // your code goes here
    TreeNode *root    = new TreeNode(10);
    root->left        = new TreeNode(12);
    root->right       = new TreeNode(15);
    root->left->left  = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);
    TreeNode* head = NULL;
    TreeNode* prev = NULL;
    bst2dll(root, head, prev);
    printLL(head);
    return 0;
}
