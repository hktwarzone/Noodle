/*
find all palindrome strings by deleting any letter from a given string
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<string> allPalindrome(string s) {
        unordered_set<string> res;
        if (s.empty()) return res;
        if (s.size() == 1) {
            res.insert(s);
            return res;
        }
        vector<vector<bool>> f(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                f[i][j] = (s[i] == s[j] && (j - i < 2 || f[i + 1][j - 1]));
                if (f[i][j]) res.insert(s.substr(i, j - i + 1));
            }
        }
        return res;
    }
};

int main() {
	// your code goes here
	Solution s;
	string t = "abcbabcba";
	unordered_set<string> res = s.allPalindrome(t);
	for (auto it = res.begin(); it != res.end(); it++) {
	    cout << *it << endl;
	}
	return 0;
}
