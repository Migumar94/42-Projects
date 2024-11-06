/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:51 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/26 20:53:21 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(100000);
	std::vector<int> vec(100000, 42);
	vec[0] = 64;
	vec[1] = 21;
	vec[2] = 0;
	try
	{
		//sp.addNumber(3);
		sp.addNumber(vec.begin(), vec.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try{
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}