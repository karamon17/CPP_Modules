#include "Point.hpp"

Fixed   abs(Fixed x)
{
	return (x < 0) ? (x * -1) : x;
}

Fixed   Square( Point const a, Point const b, Point const c ) 
{
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) + 
    ( b.getX() * ( c.getY() - a.getY() ) ) + ( c.getX() * 
    ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed   abcS = abs(Square( a, b, c ));
    Fixed   abS = abs(Square( point, a, b ));
    Fixed   bcS = abs(Square( point, b, c ));
    Fixed   caS = abs(Square( point, c, a ));
    return  ((abcS == abS + bcS + caS) && abS != 0 && bcS != 0 && caS != 0);
}