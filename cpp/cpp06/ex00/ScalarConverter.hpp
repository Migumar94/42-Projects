/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:39:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/18 16:27:37 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cmath>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <cfloat>
# include <climits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

public:
	static void convert(const std::string &str);

	class ScalarConverterException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Error: Invalid input.");
		}
	};
};

#endif