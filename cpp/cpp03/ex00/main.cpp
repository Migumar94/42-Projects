/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:05:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 17:15:20 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("CL4P-TP");

	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.attack("enemy");
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(2);
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.attack("enemy");
	clapTrap.beRepaired(5);
	clapTrap.takeDamage(10);
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);

}