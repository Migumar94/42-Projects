/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:45:36 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/21 19:53:30 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>

std::string get_str(std::string prompt)
{
	std::string str;
	while (str.empty())
	{
		std::cout << prompt;
		std::getline(std::cin >> std::ws, str);
		if (std::cin.eof())
		{
			std::cout << "Exiting program." << std::endl;
			break;
		}
	}
	return str;
}

int main()
{
	std::string command;
	Phonebook phonebook;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while(command != "EXIT")
	{
		std::cout << "Enter a command: ";
		// controlar la flag  crtl + D
		std::getline(std::cin >> std::ws, command);
		if (std::cin.eof())
		{
			std::cout << "Exiting program." << std::endl;
			break;
		}
		if (command == "ADD")
		{
			first_name= get_str("Enter first name: ");
			last_name = get_str("Enter last name: ");
			nickname = get_str("Enter nickname: ");
			phone_number = get_str("Enter phone number: ");
			darkest_secret = get_str("Enter darkest secret: ");
			phonebook.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
		}
		else if(command == "SEARCH")
		{
			phonebook.print_contacts();
			std::cout << "Enter an index: ";
			int index;
			std::cin >> index;
			if (std::cin.fail())
			{
            	std::cin.clear(); // Limpia el estado de error
            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			phonebook.print_contact(index);
			continue;
		}
		else if(command == "EXIT")
		{
			std::cout << "Exiting program." << std::endl;
		}
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
}

