/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:39:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/18 18:46:44 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

bool isNan(double d)
{
	return (d != d);
}

bool isInf(double d)
{
	return(d == d +1 && d == d *2);
}

void ScalarConverter::convert(const std::string &str)
{
	char *end;
	double d;
	d = std::strtod(str.c_str(), &end);
	if(*end == '\0')
	{
		std::cout << "char: ";
		if (isNan(d) || isInf(d) || d < CHAR_MIN || d > CHAR_MAX)
			std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<int>(d)))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (isNan(d) || isInf(d) || d < INT_MIN || d > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d);
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
		std::cout << "double: " << d;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else if (str.length() == 1 && std::isprint(str[0]))
	{
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]);
		if (str[0] - static_cast<int>(str[0]) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]);
		if (str[0] - static_cast<int>(str[0]) == 0)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << "char: ";
		if (str.length() == 1 && !std::isprint(str[0]))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		try
		{
			std::cout << atoi(str.c_str()) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "impossible" << std::endl;
		}
		std::cout << "float: ";
		try
		{
			std::cout << static_cast<float>(d);
			if(d - static_cast<int>(d) == 0)
				std::cout << ".0f" << std::endl;
			else
				std::cout << "f" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "impossible" << std::endl;
		}
		std::cout << "double: ";
		try
		{
			std::cout << d;
			if(d - static_cast<int>(d) == 0)
				std::cout << ".0" << std::endl;
			else
				std::cout << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "impossible" << std::endl;
		}
	}
}