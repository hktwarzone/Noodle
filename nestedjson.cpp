#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    string content;
    unordered_map<string, Node*> table;
    Node(string s): content(s) {}
};

class DB {
public:
    void parse(string s) {
        int start = 0;
        dbm = parseHelper(s, start);
    }
    string query(vector<string> keys) {
        unordered_map<string, Node*>* curr = &dbm;
        for (int i = 0; i < keys.size() - 1; i++) {
            curr = &(curr->at(keys[i])->table);
        }
        return curr->at(keys.back())->content;
    }
private:
    unordered_map<string, Node*> dbm;
    unordered_map<string, Node*> parseHelper(string s, int& i) {
        unordered_map<string, Node*> m;
        i += 2;
        while(s[i] != '}') {
            string name;
            while(s[i] != '=') {
                name += s[i++];
            }
            i++;
            if(s[i] != '{') {
                string value;
                while(s[i] != '|' && s[i] != '}') {
                    value += s[i++];
                }
                m[name] = new Node(value);
            }
            else {
                m[name] = new Node("");
                m[name]->table = parseHelper(s, i);
            }
            i++;
        }
        i++;
        return m;
    }
};

int main() {
	// your code goes here
	string input = "{{key=snapchat|task=interview|subkey={{key=code|time=8}}|finished=true}}";
	DB d;
	d.parse(input);
	vector<string> q1 = {"key"};
	vector<string> q2 = {"subkey","time"};
	vector<string> q3 = {"subkey","key"};
	cout << d.query(q1) << endl;
	cout << d.query(q2) << endl;
	cout << d.query(q3) << endl;
	return 0;
}
