/*
find longest palindrome subseqeunce length
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<vector<int>> f(nums.size(), vector<int>(nums.size(), 0));
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i; j < nums.size(); j++) {
                if (i == j) f[i][j] = 1;
                else if (nums[i] != nums[j]) f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                else if (i == j + 1) f[i][j] = 2;
                else f[i][j] = 2 + f[i + 1][j - 1];
            }
        }
        return f[0][nums.size() - 1];
    }
};

int main() {
	// your code goes here
	Solution s;
	vector<int> nums = {4,4,1,2,4,4};
	cout << s.longestPalindrome(nums) << endl;
	return 0;
}
