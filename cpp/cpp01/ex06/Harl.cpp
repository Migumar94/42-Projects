/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:54:56 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 23:19:59 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain( std::string level )
{
	
	void	(Harl::*complaints[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	levels[4] = { "debug", "info", "warning", "error" };

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*complaints[i])();
			return ;
		}
	}
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}