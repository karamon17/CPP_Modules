#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x1, const float y1);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point();
		void SetX(const Fixed x1);
		void SetY(const Fixed y1);
		Fixed getX() const ;
   		Fixed getY() const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif