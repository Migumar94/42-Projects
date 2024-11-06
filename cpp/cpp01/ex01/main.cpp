/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:38:11 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/20 20:43:43 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie *Horde;
	Horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}