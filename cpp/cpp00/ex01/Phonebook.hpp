/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:28:19 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/19 12:45:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Phonebook_HPP

# define Phonebook_HPP

# include "Contact.hpp"

class Phonebook
{
	private:
		Contact _contacts[8];
		int _number_contacts;

	public:
		Phonebook();
		~Phonebook();
		void add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		void print_contacts();
		void print_contact(int index);
		bool is_full();
};

#endif