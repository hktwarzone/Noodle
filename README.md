/*
Longest Substring with At Most M Distinct Characters (LC 159 extend)
*/

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringMDistinct(int m, string s) {
        if (s.size() < m) return 0;
        unordered_map<char, int> ht;
        map<int, char> next;
        int start = 0;
        int maxlength = 0;
        ht[s[0]] = 0;
        next[0] = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (ht.size() == m && ht.find(s[i]) == ht.end()) {
                maxlength = max(maxlength, i - start);
                start = next.begin()->first + 1;
                ht.erase(ht.find(next.begin()->second));
                next.erase(next.begin());
            }
            if (ht.find(s[i]) != ht.end()) {
                next.erase(next.find(ht[s[i]]));
            }
            ht[s[i]] = i;
            next[i] = s[i];
        }
        maxlength = max(maxlength, (int)s.size() - start);
        return maxlength;
    }
};

int main() {
	// your code goes here
	string s = "aaaaabbbbbc";
	Solution sol;
	cout << sol.lengthOfLongestSubstringMDistinct(3, s) << endl;
	return 0;
}
