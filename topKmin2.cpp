class Node {
public:
    int x;
    int y;
    int d;
    Node(int xx, int yy): x(xx), y(yy) {}
};

class Solution {
public:
    int kClosest(vector<Node>& array, Node& center, int k) {
        if (array.empty()) return -1;
        int n = array.size();
        if (k >= n) return n - 1;
        for (int i = 0; i < n; i++) {
            array[i].d = (array[i].x - center.x) * (array[i].x - center.x) + (array[i].y - center.y) * (array[i].y - center.y);
        }
        return kHelper(array, 0, n - 1, k);
    }
private:
    int kHelper(vector<Node>& array, int start, int end, int k) {
        Node pivot = array[end];
        int firstLarge = start;
        for (int i = start; i < end; i++) {
            if (array[i].d <= pivot.d) {
                iter_swap(array.begin() + i, array.begin() + firstLarge);
                firstLarge++;
            }
        }
        iter_swap(array.begin() + end, array.begin() + firstLarge);
        if (firstLarge - start == k - 1) return firstLarge;
        else if (firstLarge - start < k - 1)
            return kHelper(array, firstLarge + 1, end, k - (firstLarge - start + 1));
        else
            return kHelper(array, start, firstLarge - 1, k);
    }
};

int main() {
	// your code goes here
	Node a(0, 0);
	Node b(0, 1);
	Node c(2, 0);
	Node d(5, 5);
	vector<Node> array = {a, b, c, d};
	Node center(2, 2);
	Solution s;
	int res = s.kClosest(array, center, 2);
	if (res != -1) {
	    for (int i = 0; i <= res; i++) {
	        cout << "(" << array[i].x << ", " << array[i].y << ")" << endl;
	    }
	}
	return 0;
}
