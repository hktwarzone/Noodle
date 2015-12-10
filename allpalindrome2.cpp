#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> printPalindrome(string s) {
        int n = s.size();
        vector<unordered_set<string>> backtrack(n * n, unordered_set<string>());
        for (int i = 0; i < n; i++) {
            backtrack[i * n + i].insert(s.substr(i, 1));
        }
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i + gap < n; i++) {
                int j = i + gap;
                if (s[i] == s[j]) {
                    int id = (i + 1) * n + j - 1;
                    for (auto it = backtrack[id].begin(); it != backtrack[id].end(); it++) {
                        backtrack[i * n + j].insert(*it);
                        string tmp = s.substr(i, 1) + *it + s.substr(j, 1);
                        backtrack[i * n + j].insert(tmp);
                    }
                }
                else {
                    int id = (i + 1) * n + j;
                    for (auto it = backtrack[id].begin(); it != backtrack[id].end(); it++) {
                        backtrack[i * n + j].insert(*it);
                    }
                    id = i * n + j - 1;
                    for (auto it = backtrack[id].begin(); it != backtrack[id].end(); it++) {
                        backtrack[i * n + j].insert(*it);
                    }
                }
            }
        }
        vector<string> res;
        for (auto it = backtrack[n - 1].begin(); it != backtrack[n - 1].end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};

int main() {
	// your code goes here
	Solution s;
	string input = "ABCDFABCBEA";
	vector<string> output = s.printPalindrome(input);
	sort(output.begin(), output.end());
	for (int i = 0; i < output.size(); i++) {
	    cout << output[i] << endl;
	}
	return 0;
}
