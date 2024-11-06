/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:32:55 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/20 20:09:49 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int main()
{
	Zombie	*zombie;

	zombie = newZombie("Zombie1");
	zombie->announce();
	//delete zombie;
	randomChump("Zombie3");
	Zombie	zombie2("Zombie2");
	zombie2.announce();
	zombie->announce();
	delete (zombie);
	//zombie2.announce();
	return (0);
}