/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:36:55 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:54:42 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << this->_type << " says miau miau" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	*this = copy;
}

Cat &Cat::operator=(const Cat &assign) {
	if (this != &assign)
	{
		this->_type = assign._type;
		delete this->_brain;
		this->_brain = new Brain(*assign._brain);
	}
	return *this;
}
