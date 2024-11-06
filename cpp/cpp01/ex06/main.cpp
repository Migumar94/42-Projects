/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:55:25 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 23:27:18 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int harl_level( std::string level )
{
	std::string	levels[4] = { "debug", "info", "warning", "error" };

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return i;
	}
	return -1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./ex06 [debug/info/warning/error]" << std::endl;
		return 1;
	}
	Harl harl;

	switch (harl_level(argv[1]))
	{
		case 0:
			harl.complain("debug");
			break;
		case 1:
			harl.complain("info");
			break;
		case 2:
			harl.complain("warning");
			break;
		case 3:
			harl.complain("error");
			break;
		default:
			std::cout << "Invalid level." << std::endl;
			break;
	}
	return 0;
}
