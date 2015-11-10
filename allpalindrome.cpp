/*
find all palindrome strings by deleting any letter from a given string
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> allPalindrome(string s) {
        return palinHelper(s, 0, s.size() - 1);
    }
private:
    unordered_set<string> palinHelper(string s, int left, int right) {
        unordered_set<string> res;
        if (left > right) return res;
        if (left == right) {
            res.insert(s.substr(left, 1));
            return res;
        }
        for (int i = left; i <= right; i++) {
            for (int j = right; j >= i; j--) {
                if (s[i] == s[j]) {
                    unordered_set<string> next = palinHelper(s, i + 1, j - 1);
                    for (auto it = next.begin(); it != next.end(); it++) {
                        res.insert(*it);
                        res.insert(s[i] + *it + s[j]);
                    }
                }
                else {
                    unordered_set<string> next1 = palinHelper(s, i + 1, j);
                    for (auto it = next1.begin(); it != next1.end(); it++) {
                        res.insert(*it);
                    }
                    unordered_set<string> next2 = palinHelper(s, i, j - 1);
                    for (auto it = next2.begin(); it != next2.end(); it++) {
                        res.insert(*it);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
	// your code goes here
	Solution s;
	string t = "abcbba";
	unordered_set<string> res = s.allPalindrome(t);
	for (auto it = res.begin(); it != res.end(); it++) {
	    cout << *it << endl;
	}
	return 0;
}
