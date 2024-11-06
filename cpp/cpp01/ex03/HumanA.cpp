/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:35:25 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 17:14:55 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
