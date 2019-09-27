#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    string value;
    unordered_map<string, Node*> table;
    Node() {}
    Node(string v) : value(v) {}
};

class Solution {
public:
    Solution() {
        root = new Node();
    }
    ~Solution() {
        delete root;
    }
    void parse(string& input) {
        int start = 0;
        parseInternal(root, input, start);
    }
    string query(vector<string>& keys) {
        Node* curr = root;
        for (int i = 0; i < keys.size(); i++) {
            curr = curr->table[keys[i]];
        }
        return curr->value;
    }
private:
    Node* root;
    void parseInternal(Node* curr, string& input, int& index) {
        if (input.substr(index, 2) == "{{") {
            index += 2;
            while(input[index] != '}') {
                string currkey;
                while(input[index] != '=') {
                    currkey += input[index++];
                }
                index++;
                if(input[index] != '{') {
                    string val;
                    while(input[index] != '|' && input[index] != '}') {
                        val += input[index++];
                    }
                    curr->table[currkey] = new Node(val);
                }
                else {
                    curr->table[currkey] = new Node();
                    parseInternal(curr->table[currkey], input, index);
                }
                index++;
            }
            index++;
        }
    }
};

int main()
{
    string input = "{{key=snapchat|task=interview|subkey={{key=code|time=8|subsub={{abc=def}}}}|finished=true}}";
    Solution s;
    s.parse(input);
    vector<string> q1 = {"key"};
	  vector<string> q2 = {"subkey","time"};
	  vector<string> q3 = {"subkey","subsub","abc"};
    cout << s.query(q1) << endl;
    cout << s.query(q2) << endl;
    cout << s.query(q3) << endl;
    return 0;
}
