#include <iostream>
#include <memory>
#include <stack>
#include <vector>

using namespace std;

class NestedIterator {
public:
    struct node_t {
        node_t(int v): value(v) {}
        node_t(const initializer_list<node_t>& l): nested(make_shared<vector<node_t>>(l)){}
        shared_ptr<vector<node_t>> getNested() { return static_pointer_cast<vector<node_t>>(nested); }
        
        shared_ptr<void> nested;
        int value;
    };
    
    NestedIterator(const initializer_list<node_t>& l) {
        st.push(make_shared<vector<node_t>>(l));
        if (!st.top()->empty()) index.push(0);
    }
    
    bool hasNext() { return !st.empty(); }
    int next() {
        while(!st.empty()) {
            shared_ptr<vector<node_t>> curr = st.top();
            int curr_index = index.top();
            index.pop();
            if (curr_index + 1 >= curr->size()) st.pop();
            else index.push(curr_index + 1);
            
            if (!curr->at(curr_index).nested) return curr->at(curr_index).value;
            else {
                st.push(curr->at(curr_index).getNested());
                index.push(0);
            }
        }
        return -1;
    }
private:
    stack<int> index;
    stack<shared_ptr<vector<node_t>>> st;
};


int main() {
	// your code goes here
	NestedIterator it {{ 1 }, 2, { 3, {4, 5}, { 6, 7, { 8 }}}};
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;
	return 0;
}
