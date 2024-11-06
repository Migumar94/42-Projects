/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:40:04 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:56:03 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << this->_type << " says miau miau" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &assign) {
	if (this != &assign)
	{
		this->_type = assign._type;
	}
	return *this;
}