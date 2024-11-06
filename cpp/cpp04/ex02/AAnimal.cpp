/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:37:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:30:08 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"


AAnimal::AAnimal() : _type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "Animal type constructor called." << std::endl;
}
AAnimal::~AAnimal() {
	std::cout << "Animal destructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &assign) {
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}