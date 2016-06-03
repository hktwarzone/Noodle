/*
N - normal, L - late, A - absent
consecutive three Ls => false
any two As => false
other => true
calculate the count of false cases for 30 days
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> x(30, 0);
    vector<int> y(30, 0);
    vector<int> z(30, 0);
    vector<int> t(30, 0);
    x[0] = 1;
    y[0] = 1;
    t[0] = 2;
    for (int i = 1; i < 30; i++) {
        x[i] = x[i - 1] + y[i - 1] + z[i - 1];
        y[i] = x[i - 1];
        z[i] = y[i - 1];
        t[i] = x[i] + y[i] + z[i];
    }
    long long sum = 0;
    for (int i = 1; i <= 28; i++) {
        sum += t[i] * t[29 - i];
    }
    sum += 2 * t[29];
    long long total = (long long)pow(3.0, 30.0);
    cout << total - sum << endl;
	return 0;
}
