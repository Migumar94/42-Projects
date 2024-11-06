/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:05:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 18:02:48 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap FragTrap("CL4P-TP");

	FragTrap.attack("enemy");
	FragTrap.takeDamage(5);
	FragTrap.beRepaired(3);
	FragTrap.attack("enemy");
	FragTrap.takeDamage(3);
	FragTrap.beRepaired(2);
	FragTrap.attack("enemy");
	FragTrap.attack("enemy");
	FragTrap.attack("enemy");
	FragTrap.attack("enemy");
	FragTrap.attack("enemy");
	FragTrap.beRepaired(5);
	FragTrap.highFivesGuys();
	FragTrap.takeDamage(10);
	FragTrap.takeDamage(10);
	FragTrap.beRepaired(10);

}