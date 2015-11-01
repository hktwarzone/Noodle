#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution{
public:
    pair<int, int> prefixRange(vector<string>& array, string& p) {
        if (array.empty()) return make_pair(-1, -1);
        int left = 0;
        int right = array.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isPrefix(array[mid], p)) { right = mid; }
            else if (array[mid] > p) { right = mid; }
            else { left = mid + 1; }
        }
        if (!isPrefix(array[left], p)) return make_pair(-1, -1);
        int lb = left;
        left = 0;
        right = array.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (isPrefix(array[mid], p)) { left = mid; }
            else if (array[mid] < p) { left = mid; }
            else { right = mid - 1; }
        }
        return make_pair(lb, left);
    }
private:
    bool isPrefix(string& s, string& p) {
        return (s.size() >= p.size() && s.substr(0, p.size()) == p);
    }
};

int main() {
	// your code goes here
	pair<int, int> res;
	vector<string> A = {"A", "AAB", "AAC", "AAD", "AAE", "DE"};
	string pattern = "AA";
	Solution s;
	res = s.prefixRange(A, pattern);
	cout << "(" << res.first << ", " << res.second << ")" << endl;
	return 0;
}
