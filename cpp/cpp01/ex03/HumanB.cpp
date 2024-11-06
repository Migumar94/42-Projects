/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:35:19 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 17:15:30 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
