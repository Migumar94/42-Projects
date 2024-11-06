/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:54:45 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/22 20:57:40 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:
	Harl();
	~Harl();
	void	complain( std::string level );
};

#endif