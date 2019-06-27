#pragma once
#include "Point.h"

ostream& operator<<(ostream& stream, Point p) {
	stream << "(" << p.getX() << ", " << p.getY() << ")";
	return stream;
}

Point Point::operator+(Point p) {
	return Point(this->getX() + p.getX(), this->getY() + p.getY());
}

void Point::operator+=(Point p) {
	this->addX(p.getX());
	this->addY(p.getY());
}