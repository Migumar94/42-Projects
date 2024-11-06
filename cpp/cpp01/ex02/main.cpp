/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:53:59 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/20 21:22:53 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string : " << &str << std::endl;
	std::cout << "Address using stringPTR " << stringPTR << std::endl;
	std::cout << "Address using stringREF " << &stringREF << std::endl;
	std::cout << "Content of the string : " << str << std::endl;
	std::cout << "Content using stringPTR " << *stringPTR << std::endl;
	std::cout << "Content using stringREF " << stringREF << std::endl;
	
}