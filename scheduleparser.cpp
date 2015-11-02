/* Command stream dumpout
*/

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

class Solution {
public:
    void logger(vector<vector<string>>& commands) {
        list<pair<int, int>> m;
        unordered_map<int, list<pair<int, int>>::iterator> ht;
        list<pair<int, int>>::iterator it = m.begin();
        for (int i = 0; i < commands.size(); i++) {
            int taskid = stoi(commands[i][1]);
            int ts = stoi(commands[i][2]);
            if (commands[i][0] == "start") {
                m.push_back(make_pair(taskid, ts));
                ht[taskid] = ++it;
            }
            else {
                if(ht[taskid] == m.begin()) {
                    cout << taskid << ", " << ts - m.begin()->second << endl;
                    m.pop_front();
                    ht.erase(ht.find(taskid));
                    while(!m.empty() && m.begin()->second < 0) {
                        cout << m.begin()->first << ", " << -m.begin()->second << endl;
                        ht.erase(ht.find(m.begin()->first));
                        m.pop_front();
                    }
                }
                else {
                    ht[taskid]->second = -(ts - ht[taskid]->second);
                }
            }
        }
    }
};

int main() {
	// your code goes here
	Solution s;
	vector<string> command1 = {"start", "5", "8"};
	vector<string> command2 = {"start", "0", "10"};
	vector<string> command3 = {"start", "2", "13"};
	vector<string> command4 = {"start", "1", "14"};
	vector<string> command5 = {"end", "0", "20"};
	vector<string> command6 = {"start", "7", "30"};
	vector<string> command7 = {"end", "2", "40"};
	vector<string> command8 = {"end", "7", "60"};
	vector<string> command9 = {"end", "5", "90"};
	vector<string> command10 = {"end", "1", "100"};
	vector<vector<string>> commands = {command1, command2, command3, command4, command5, command6, command7, command8, command9, command10};
	s.logger(commands);
	return 0;
}
