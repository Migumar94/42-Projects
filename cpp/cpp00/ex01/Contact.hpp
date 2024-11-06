/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:39:27 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/19 12:43:36 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		Contact();
		~Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_darkest_secret();
		void print_contact();
		bool is_empty();
};

#endif