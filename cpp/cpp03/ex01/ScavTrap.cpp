/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:12:19 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 17:46:29 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{

	std::cout << "ScavTrap constructor called." << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void ScavTrap::guardGate()
{
	if(_hitPoints == 0)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return ;
	}
	if(_energyPoints == 0)
	{
		std::cout << _name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
	_energyPoints--;
}

void ScavTrap::attack(std::string const &target)
{
	if(_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	if(_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}
