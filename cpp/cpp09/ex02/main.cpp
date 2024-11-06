/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:31:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/04 17:42:20 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pm;
	if (argc < 2)
	{
		std::cout << "Please provide at least one argument." << std::endl;
		return (1);
	}
	pm.fillcontainers(argv);
	pm.sortcontainers();
	return (0);
}