/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:31:07 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/20 20:38:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie *zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return (zombie);
}