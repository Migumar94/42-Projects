/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:38:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/26 13:34:59 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <set>


int main()
{
	
	std::vector<int> v;
    v.push_back(7);
    v.push_back(5);
    v.push_back(16);
    v.push_back(8);
    
	try
	{
		std::cout << easyfind(v, 5) << std::endl;
		std::cout << easyfind(v, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::set<int> s;
	s.insert(7);
	s.insert(5);
	s.insert(16);
	s.insert(8);

	try
	{
		std::cout << easyfind(s, 5) << std::endl;
		std::cout << easyfind(s, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}