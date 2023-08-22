#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = fixed.getRawBits();
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_value / (float)(1 << this->_bits));
}

int Fixed::toInt( void ) const {
	return (this->_value >> this->_bits);
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
    return (out);
}

bool    Fixed::operator>(const Fixed &fixed) const {
	return (this->_value > fixed.getRawBits());
}

bool    Fixed::operator<(const Fixed &fixed) const {
	return (this->_value < fixed.getRawBits());
}
bool    Fixed::operator>=(const Fixed &fixed) const {
	return (this->_value >= fixed.getRawBits());
}
bool    Fixed::operator<=(const Fixed &fixed) const {
	return (this->_value <= fixed.getRawBits());
}
bool    Fixed::operator==(const Fixed &fixed) const {
	return (this->_value == fixed.getRawBits());
}
bool    Fixed::operator!=(const Fixed &fixed) const {
	return (this->_value != fixed.getRawBits());
}

Fixed   Fixed::operator+(const Fixed &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}
Fixed   Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}
Fixed   Fixed::operator*(const Fixed &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}
Fixed   Fixed::operator/(const Fixed &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed&  Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed   Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed&  Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed   Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}