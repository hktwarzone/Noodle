/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} 
valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        if (coins.empty()) return 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> f(n, vector<int>(k + 1, 0));
        for(int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) {
                    f[i][j] = 1;
                }
                else {
                    if (i > 0) {
                        f[i][j] += f[i - 1][j];
                    } 
                    if (j >= coins[i]) {
                        f[i][j] += f[i][j - coins[i]];
                    }
                }
            }
        }
        return f[n - 1][k];
    }
};

int main() {
	// your code goes here
	vector<int> coins = {2, 5, 3, 6};
	int k = 10;
	Solution s;
	cout << s.coinChange(coins, k) << endl;
	return 0;
}
