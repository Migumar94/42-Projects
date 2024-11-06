/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:43:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/18 14:40:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);

	return 0;
}