/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:35:10 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 17:21:26 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
class	Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string&	getType();
		void	setType(std::string type);
};

#endif