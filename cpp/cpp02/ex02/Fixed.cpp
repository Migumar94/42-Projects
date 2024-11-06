/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:58:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 12:38:37 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int ft_pow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return result;
}

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value * ft_pow(2, _fractionalBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * ft_pow(2, _fractionalBits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = copy.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / ft_pow(2, _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return _value / ft_pow(2, _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}

//arithmetic operators

Fixed	Fixed::operator+(Fixed const &value) const
{
	return Fixed(this->toFloat() + value.toFloat());
}

Fixed	Fixed::operator-(Fixed const &value) const
{
	return Fixed(this->toFloat() - value.toFloat());
}


Fixed	Fixed::operator*(Fixed const &value) const
{
	return Fixed(this->toFloat() * value.toFloat());
}

Fixed	Fixed::operator/(Fixed const &value) const
{
	return Fixed(this->toFloat() / value.toFloat());
}

//increment and decrement operators
Fixed	&Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}
//comparison operators
int		Fixed::operator>(Fixed const &value) const
{
	return this->toFloat() > value.toFloat();
}

int		Fixed::operator<(Fixed const &value) const
{
	return this->toFloat() < value.toFloat();
}

int		Fixed::operator>=(Fixed const &value) const
{
	return this->toFloat() >= value.toFloat();
}

int		Fixed::operator<=(Fixed const &value) const
{
	return this->toFloat() <= value.toFloat();
}

int		Fixed::operator==(Fixed const &value) const
{
	return this->toFloat() == value.toFloat();
}

int		Fixed::operator!=(Fixed const &value) const
{
	return this->toFloat() != value.toFloat();
}

//static comparison operators

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if(a < b)
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if(a < b)
		return a;
	return b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if(a < b)
		return a;
	return b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if(a < b)
		return a;
	return b;
}



