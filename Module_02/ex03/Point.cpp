#include "Point.hpp"

Point::Point(): _x(0), _y(0) {
}

Point::Point(const float x1, const float y1): _x(x1), _y(y1) {

}

Point::Point(const Point &point): _x(point._x), _y(point._y) {

}

Point &Point::operator=(const Point &point) {
	(Fixed)this->_x = point._x;
	(Fixed)this->_y = point._y;
	return (*this);
}

void Point::SetX(const Fixed x1) {
	(Fixed)this->_x = x1;
}

void Point::SetY(const Fixed y1) {
	(Fixed)this->_y = y1;
}

Fixed Point::getX() const {
	return (this->_x);
}

Fixed Point::getY() const {
	return (this->_y);
}

Point::~Point() {

}