/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:28:13 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/19 21:02:31 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_number_contacts = 0;
}

Phonebook::~Phonebook(void)
{
}

void Phonebook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	if(this->_number_contacts >=8)
	{
		this->_contacts[this->_number_contacts % 8] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	}
	this->_contacts[this->_number_contacts % 8] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->_number_contacts++;
}

void Phonebook::print_contacts()
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8 && i< this->_number_contacts; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if(this->_contacts[i].get_first_name().length() > 10)
			std::cout << this->_contacts[i].get_first_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_first_name().substr(0, 10) << "|";
		if(this->_contacts[i].get_last_name().length() > 10)
			std::cout << this->_contacts[i].get_last_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_last_name().substr(0, 10) << "|";
		if(this->_contacts[i].get_nickname().length() > 10)
			std::cout << this->_contacts[i].get_nickname().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << this->_contacts[i].get_nickname().substr(0, 10) << std::endl;
	}
}

void Phonebook::print_contact(int index)
{
	if (index < 1 || index > this->_number_contacts)
	{
		std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		return ;
	}
	this->_contacts[index - 1].print_contact();
}

bool Phonebook::is_full()
{
	return (this->_number_contacts == 8);
}

