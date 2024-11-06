/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:36:52 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:49:26 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << this->_type << " says guau guau" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	*this = copy;
}

Dog &Dog::operator=(const Dog &assign) {
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}