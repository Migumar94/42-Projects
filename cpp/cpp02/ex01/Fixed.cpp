/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:58:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 12:28:03 by migumar2         ###   ########.fr       */
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
