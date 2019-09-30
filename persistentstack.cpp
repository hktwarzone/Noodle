#include <iostream>
using namespace std;

class Node {
public:
	int val;
	shared_ptr<Node> next;
	Node(int v, shared_ptr<Node> n) : val(v), next(n) {}
};

class PStack {
public:
	PStack(shared_ptr<Node> h) : head(h) {}
	int size() {
		int i = 0;
		auto curr = head;
		while(curr != nullptr) {
			i++;
			curr = curr->next;
		}
		return i;
	}
	shared_ptr<PStack> push(int x) {
		shared_ptr<Node> newhead = make_shared<Node>(x, head);
		return make_shared<PStack>(newhead);
	}
	shared_ptr<PStack> pop() {
		if (head != nullptr) {
			return make_shared<PStack>(head->next);
		}
		return nullptr;
	}
	void print() {
		auto curr = head;
		while(curr != nullptr) {
			cout << curr->val << " ";
			curr = curr->next;
		}
		cout << endl;
	}
private:
	shared_ptr<Node> head;
};

int main(int argc, char** argv) {
	auto stk = new PStack(nullptr);
	stk->print();
	auto stk2 = stk->push(17);
	stk2->print();
	auto stk3 = stk->push(28);
	stk3->print();
	auto stk4 = stk->push(39);
	stk4->print();
	auto stk5 = stk2->push(40);
	stk5->print();
	auto stk6 = stk5->pop();
	stk6->print();
	auto stk7= stk3->pop();
	stk7->print();
}
