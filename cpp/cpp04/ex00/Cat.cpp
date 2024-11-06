/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:36:55 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:50:31 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	_type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << this->_type << " says miau miau" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy) {
	*this = copy;
}

Cat &Cat::operator=(const Cat &assign) {
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}
