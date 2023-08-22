#include "Point.hpp"

Fixed   abs(Fixed x)
{
    if (x < 0)
        return x * -1;
    return x;
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
    Fixed   aS = abs(Square( point, a, b ));
    Fixed   bS = abs(Square( point, b, c ));
    Fixed   cS = abs(Square( point, c, a ));
    return  ((abcS == aS + bS + cS) && aS != 0 && bS != 0 && cS != 0);
}