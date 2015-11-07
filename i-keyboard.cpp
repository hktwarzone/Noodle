/*
http://poj.org/problem?id=1404
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class IKeyPhone {
public:
    vector<vector<int>> distribute(int n, vector<int>& freq) {
        int k = freq.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= k; i++) {
            f[1][i] = f[1][i - 1] + i * freq[i - 1];
        }
        vector<vector<int>> psum(k + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= k; j++) {
                psum[i][j] = psum[i][j - 1] + freq[j - 1];
            }
        }
        vector<vector<int>> path(n + 1, vector<int>(k + 1, 0));
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= k; j++) {
                f[i][j] = INT_MAX;
                int pushcount = 0;
                for (int p = j - 1; p >= i - 1; p--) {
                    pushcount += psum[p + 1][j];
                    if (f[i - 1][p] + pushcount < f[i][j]) {
                        f[i][j] = f[i - 1][p] + pushcount;
                        path[i][j] = p;
                    }
                }
            }
        }
        return path;
    }
    void print(vector<vector<int>> path, string words) {
        int n = path.size() - 1;
        int k = path[0].size() - 1;
        int last = k;
        vector<string> output;
        for (int i = n; i >= 1; i--) {
            output.push_back(words.substr(path[i][last], last - path[i][last]));
            last = path[i][last];
        }
        for (int i = output.size() - 1; i >= 0; i--) {
            cout << output[i] << endl;
        }
    }
};

int main() {
	// your code goes here
	int n = 8;
	vector<int> freq = {3371,589,1575,1614,6212,971,773,1904,2989,123,209,1588,1513,2996,3269,1080,121,2726,3083,4368,1334,518,752,427,733,871};
	IKeyPhone s;
	string key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	s.print(s.distribute(n, freq), key);
	return 0;
}
