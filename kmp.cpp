#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KMP {
public:
    void matching(string s, string p) {
        if (p.size() > s.size()) return;
        vector<int> failure(p.size(), 0);
        failure[0] = -1;
        for (int i = 1, j = failure[0]; i < p.size(); i++) {
            while(j >= 0 && p[i] != p[j + 1]) {
                j = failure[j];
            }
            if (p[i] == p[j + 1]) j++;
            failure[i] = j;
        }
        for (int i = 0, j = -1; i < s.size(); i++) {
            while(j >= 0 && s[i] != p[j + 1]) {
                j = failure[j];
            }
            if (s[i] == p[j + 1]) j++;
            if (j == p.size() - 1) {
                cout << "Found pattern at index " << i - j << endl;
                j = failure[j];
            }
        }
    }
};

int main() {
	// your code goes here
	string s = "AABAACAADAABAAABAA";
	string p = "AABA";
	KMP kmpinst;
	kmpinst.matching(s, p);
	return 0;
}
