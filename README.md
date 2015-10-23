/*
Given a sorted int vector and a target, output the count of appearances of the target
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& v, int target) {
        if (v.empty()) return -1;
        if (v[0] >= target) return 0;
        int n = v.size();
        if (v[n - 1] < target) return n;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (v[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    int upperBound(vector<int>& v, int target) {
        if (v.empty()) return -1;
        if (v[0] >= target) return 0;
        int n = v.size();
        if (v[n - 1] < target) return n;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (v[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
	// your code goes here
	vector<int> v = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
	int target = 4;
	Solution s;
	int lb = s.lowerBound(v, target);
	int ub = s.upperBound(v, target);
	cout << "count of " << target << " = " << ub - lb << endl;
	return 0;
}
