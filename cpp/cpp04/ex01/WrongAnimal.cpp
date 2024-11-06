/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:39:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:38 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal type constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << this->_type << " does random sound" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign) {
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}