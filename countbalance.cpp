#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long balanceTree(int n) {
        if (n < 2) return 1;
        vector<vector<long long>> f(n + 1, vector<long long>(n + 1, 0));
        f[0][0] = 1;
        f[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int depth = 2; depth <= i; depth++) {
                for (int k = 0; k <= i - 1; k++) {
                    f[i][depth] += f[k][depth - 1] * f[i - k - 1][depth - 2];
                    f[i][depth] += f[k][depth - 1] * f[i - k - 1][depth - 1];
                    f[i][depth] += f[k][depth - 2] * f[i - k - 1][depth - 1];
                }
            }
        }
        long long res = 0;
        for (int i = 0; i <= n; i++) {
            res += f[n][i];
        }
        return res;
    }
};

int main() {
	// your code goes here
	Solution s;
	s.balanceTree(50);
	return 0;
}
