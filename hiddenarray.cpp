#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HiddenArray {
public:
    int get(int i) {
        if (i < 0 || i >= realarray.size()) return 0;
        return realarray[i];
    }
    HiddenArray(vector<int>& v): realarray(v) {
        sort(realarray.begin(), realarray.end());
    }
private:
    vector<int> realarray;
};

class Solution {
public:
    bool search(HiddenArray& A, int target) {
        if (A.get(0) == 0) return false;
        int right = 1;
        while(A.get(right) != 0 && A.get(right) < target) {
            right *= 10;
        }
        int left = 0;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (A.get(mid) == target) return true;
            else if (A.get(mid) == 0 || A.get(mid) > target) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return (A.get(left) == target);
    }
};

int main() {
	// your code goes here
	vector<int> input = {1,4,7,2,5,8,3,6,9};
	HiddenArray A(input);
	Solution s;
	cout << s.search(A, 1) << endl;
	cout << s.search(A, 5) << endl;
	cout << s.search(A, 10) << endl;

	return 0;
}
