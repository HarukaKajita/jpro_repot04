#pragma once
#include "Node.h"
ostream& operator<<(ostream& stream, Point p) {
	stream << "(" << p.getX() << ", " << p.getY() << ")";
	return stream;
}
