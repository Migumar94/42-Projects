/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:58:43 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 12:35:41 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int _value;
	static const int _fractionalBits = 8;
public:
	Fixed(void);
	Fixed(Fixed const &copy);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);
	Fixed	&operator=(Fixed const &copy);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	//arithmetic operators
	Fixed	operator+(Fixed const &value) const;
	Fixed	operator-(Fixed const &value) const;
	Fixed	operator*(Fixed const &value) const;
	Fixed	operator/(Fixed const &value) const;
	//increment and decrement operators
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	//comparison operators
	int		operator>(Fixed const &value) const;
	int		operator<(Fixed const &value) const;
	int		operator>=(Fixed const &value) const;
	int		operator<=(Fixed const &value) const;
	int		operator==(Fixed const &value) const;
	int		operator!=(Fixed const &value) const;
	//static comparison operators
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);


	
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);//tostring

#endif