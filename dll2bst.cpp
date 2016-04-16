// Doubly Linked List conversion to BST
// Note: count total # of elements, maintain a global TreeNode* (head) to track current "ListNode" 
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

TreeNode* dll2bst(TreeNode*& head, int count) {
    if (count <= 0) return NULL;
    TreeNode* left = dll2bst(head, count / 2);
    TreeNode* root = head;
    root->left = left;
    head = head->right;
    root->right = dll2bst(head, count - count / 2 - 1);
    return root;
}

int countNode(TreeNode* head) {
    if (!head) return 0;
    int count = 0;
    while(head) {
        count++;
        head = head->right;
    }
    return count;
}

void preOrder(TreeNode* root)
{
    if (!root) return;
    cout << root->value << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void pushList(TreeNode*& head, int v) {
    TreeNode* newNode = new TreeNode(v);
    if (head) {
        head->left = newNode;
        newNode->right = head;
    }
    head = newNode;
}

int main() {
    // your code goes here
    TreeNode* head = NULL;
	pushList(head, 7);
    pushList(head, 6);
    pushList(head, 5);
    pushList(head, 4);
    pushList(head, 3);
    pushList(head, 2);
    pushList(head, 1);
    int n = countNode(head);
    TreeNode* root = dll2bst(head, n);
    preOrder(root);
    return 0;
}
