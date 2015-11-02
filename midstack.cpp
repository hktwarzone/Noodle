/*
http://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
*/
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x) {
        val = x;
        next = prev = NULL;
    }
};

class MidStack {
public:
    MidStack() {
        head = mid = NULL;
        size = 0;
    }
    void push(int x) {
        Node* curr = new Node(x);
        if (head != NULL) {
            curr->next = head;
            head->prev = curr;
        }
        head = curr;
        size++;
        if (size == 1) {
            mid = head;
        }
        else if (size & 1) {
            mid = mid->prev;            
        }
    }
    int pop() {
        if (head == NULL) {
            return -1;
        }
        Node* delNode = head;
        int res = delNode->val;
        head = head->next;
        size--;
        if (size == 0) {
            mid = NULL;
        }
        else if (!(size & 1)) {
            mid = mid->next;
        }
        delete delNode;
        return res;
    }
    int findMiddle() {
        if (mid != NULL) return mid->val;
        else return -1;
    }
    void deleteMiddle() {
        if (size == 1) {
            pop();
        }
        else {
            Node* delNode = mid;
            if (mid->next) {
                mid->next->prev = mid->prev;
            }
            if (mid->prev) {
                mid->prev->next = mid->next;
            }
            if (size & 1) {
                mid = mid->next;
            }
            else {
                mid = mid->prev;
            }
            size--;
            delete delNode;
        }
    }
private:
    Node* head;
    Node* mid;
    int size;
};

int main() {
	// your code goes here
	MidStack st;
	st.push(11);
	st.push(22);
	st.push(33);
	st.push(44);
	st.push(55);
	st.push(66);
	st.push(77);

    cout << "Item popped is " << st.pop() << endl;
    cout << "Item popped is " << st.pop() << endl;
    cout << "Middle Element is " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element is " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element is " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element is " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element is " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element is " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element is " << st.findMiddle() << endl;
    return 0;
}
