/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:35:22 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 17:11:25 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void	attack(void);
};