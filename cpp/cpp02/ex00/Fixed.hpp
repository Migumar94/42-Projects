/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:58:43 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/23 14:15:00 by migumar2         ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif