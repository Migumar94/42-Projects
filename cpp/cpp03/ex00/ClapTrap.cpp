/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:06:30 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/03 17:08:17 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if(_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	if(_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if((int)_hitPoints-(int)amount < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	if(_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	if(_hitPoints > 10)
		_hitPoints = 10;
	std::cout << "ClapTrap " << _name << " has been repaired for " << amount << " points!" << std::endl;
}