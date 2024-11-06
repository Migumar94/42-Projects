/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:09:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:30:32 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea ";
	
	std::cout << "Brain constructor called!" << std::endl;

}

Brain::~Brain()
{
	delete[] _ideas;
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain &Brain::operator=(const Brain &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = assign._ideas[i];
	}
	return *this;
}
