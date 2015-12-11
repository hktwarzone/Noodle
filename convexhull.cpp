/*
http://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
*/

#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int a, int b): x(a), y(b) {}
};

class Solution {
public:
    vector<Point> hull(vector<Point>& points) {
        if (points.size() < 3) return vector<Point>();
        int leftmost = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[i].x < points[leftmost].x) {
                leftmost = i;
            }
        }
        int curr = leftmost;
        int next = -1;
        vector<Point> res;
        do {
            res.push_back(points[curr]);
            next = (curr + 1) % points.size();
            for (int i = 0; i < points.size(); i++) {
                if (orient(points[curr], points[i], points[next]) == 2) {
                    next = i;
                }
            }
            curr = next;
        } while(next != leftmost);
        return res;
    }
private:
    int orient(Point p, Point q, Point r) {
        int val = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }
};

int main() {
	// your code goes here
	vector<Point> input;
	input.push_back(Point(0,3));
	input.push_back(Point(2,2));
	input.push_back(Point(1,1));
	input.push_back(Point(2,1));
	input.push_back(Point(3,0));
	input.push_back(Point(0,0));
	input.push_back(Point(3,3));
	Solution s;
	vector<Point> output = s.hull(input);
    for (int i = 0; i < output.size(); i++) {
        cout << "(" << output[i].x << ", " << output[i].y << ")" << endl;
    }
	return 0;
}
