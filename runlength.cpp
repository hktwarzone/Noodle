/*
Run Length Encoding
Given an input string, write a function that returns the Run Length Encoded string for the input string.

For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    string runlength(string& s) {
        string res;
        if (s.empty()) return res;
        char curr = s[0];
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == curr) {
                count++;
            }
            else {
                res += curr + to_string(count);
                curr = s[i];
                count = 1;
            }
        }
        res += curr + to_string(count);
        return res;
    }
};

int main() {
	// your code goes here
	Solution s;
	string input;
	while(getline(cin, input)) {
	    cout << s.runlength(input) << endl;
	}
	return 0;
}
