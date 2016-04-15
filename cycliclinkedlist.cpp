#include <iostream>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* prev;
    ListNode* next;
    ListNode(int v): value(v) {
        prev = NULL;
        next = NULL;
    }
};

class List {
public:
    ListNode* head;
    List() {
        head = NULL;
    }
    void addNode(int v) {
        if (!head) {
            head = new ListNode(v);
            head->next = head;
            head->prev = head;
            return;
        }
        else {
            ListNode* curr = head;
            while (curr->next != head && curr->value < v) {
                curr = curr->next;
            }
            ListNode* newNode = new ListNode(v);
            if (curr->next == head && curr->value < v) {
                curr->next = newNode;
                newNode->next = head;
                head->prev = newNode;
                newNode->prev = curr;
            }
            else {
                if (curr == head) head = newNode;
                curr->prev->next = newNode;
                newNode->next = curr;
                newNode->prev = curr->prev;
                curr->prev = newNode;
            }
        }
    }
    void printNode() {
        if (!head) {
            cout << "NULL" << endl;
            return;
        }
        cout << head->value << " -> ";
        ListNode* curr = head->next;
        while(curr != head) {
            cout << curr->value << " -> ";
            curr=curr->next;
        }
        cout << endl;
    }
};

int main() {
	// your code goes here
	List l;
	l.printNode();
	l.addNode(2);
	l.printNode();
	l.addNode(5);
	l.printNode();
	l.addNode(3);
	l.printNode();
	l.addNode(4);
	l.printNode();
	l.addNode(1);
	l.printNode();
	return 0;
}
