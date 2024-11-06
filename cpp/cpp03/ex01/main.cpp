/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:05:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 17:49:51 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap ScavTrap("CL4P-TP");

	ScavTrap.attack("enemy");
	ScavTrap.takeDamage(5);
	ScavTrap.beRepaired(3);
	ScavTrap.attack("enemy");
	ScavTrap.takeDamage(3);
	ScavTrap.beRepaired(2);
	ScavTrap.attack("enemy");
	ScavTrap.attack("enemy");
	ScavTrap.attack("enemy");
	ScavTrap.attack("enemy");
	ScavTrap.attack("enemy");
	ScavTrap.beRepaired(5);
	ScavTrap.guardGate();
	ScavTrap.takeDamage(10);
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(10);

}