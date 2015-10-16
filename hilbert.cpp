#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int hilbert(int x, int y, int k) {
   //cout << "(x, y, k) = (" << x << ", " << y << ", " << k << ")" << endl;
   if (k == 1) {
      if (x == 0 && y == 0) return 0;
      else if (x == 0 && y == 1) return 1;
      else if (x == 1 && y == 1) return 2;
      else return 3;
   }

   double cx = (pow(2, k) - 1) / 2;
   double cy = (pow(2, k) - 1) / 2;

   if (x < cx && y < cy) {
      return hilbert(y, x, k - 1);
   }
   else if (x < cx && y > cy) {
      return pow(4, k - 1) + hilbert(x, y - pow(2, k - 1), k - 1);
   }
   else if (x > cx && y > cy) {
      return 2 * pow(4, k - 1) + hilbert(x - pow(2, k - 1), y - pow(2, k - 1), k - 1);
   }
   else {
      return 3 * pow(4, k - 1) + hilbert(-(y - pow(2, k - 1) + 1), -(x - pow(2, k) + 1), k - 1);
   }
}

int main() {
   int k;
   while(1) {
      cin >> k;
      for (int j = pow(2, k) - 1; j >= 0; j--) {
        for (int i = 0; i < pow(2, k); i++) {
            cout << setw(5) << hilbert(i, j, k) << " ";
        }
        cout << endl;
      }
   }
   return 0;
}
