#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int sameDigit(vector<pair<int, int>>& A, vector<pair<int, int>>& B) {
        if (A.empty()) return 0;
        int a_ptr = 0;
        int b_ptr = 0;
        int a_start = 0;
        int b_start = 0;
        int a_end = 0;
        int b_end = 0;
        int count = 0;
        while(a_ptr < A.size() && b_ptr < B.size()) {
            a_end = a_start + A[a_ptr].second - 1;
            b_end = b_start + B[b_ptr].second - 1;
            if (A[a_ptr].first == B[b_ptr].first) {
                count += max(0, (min(a_end, b_end) - max(a_start, b_start) + 1));
                a_ptr++;
                a_start = a_end + 1;
                b_ptr++;
                b_start = b_end + 1;
            }
            else {
                if (a_end < b_end) {
                    a_ptr++;
                    a_start = a_end + 1;
                }
                else if (a_end > b_end) {
                    b_ptr++;
                    b_start = b_end + 1;
                }
                else {
                    a_ptr++;
                    a_start = a_end + 1;
                    b_ptr++;
                    b_start = b_end + 1;
                }
            }
        }
        return count;
    }
};

int main() {
	// your code goes here
	//vector<pair<int, int>> A = {make_pair(1,3), make_pair(0,2), make_pair(1,2)};
	//vector<pair<int, int>> B = {make_pair(1,2), make_pair(0,4), make_pair(1,1)};
	vector<pair<int, int>> A = {make_pair(1,3), make_pair(0,2), make_pair(1,2)};
	vector<pair<int, int>> B = {make_pair(0,2), make_pair(1,3), make_pair(0,1), make_pair(1,1)};
	Solution s;
	cout << s.sameDigit(A, B) << endl;
	return 0;
}
