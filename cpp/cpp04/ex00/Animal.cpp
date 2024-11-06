/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:37:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 14:38:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal type constructor called." << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << this->_type <<" does random sound" << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;
}

Animal &Animal::operator=(const Animal &assign) {
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}