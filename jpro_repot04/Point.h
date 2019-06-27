#pragma once
#include <iostream>
using namespace std;

#pragma once
class Point {
private:
	int x, y;
	void addX(int x) { this->x += x; };
	void addY(int y) { this->y += y; };
public:
	Point(int _x = -1, int _y = -1) {
		x = _x;
		y = _y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	Point operator+(Point);
	void operator+=(Point);
};

ostream& operator<<(ostream&, Point);