/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:43:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/15 19:22:34 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat	b("migumar", 42);
	std::cout << b;

	try {
		Form	f1("f1", 1000, 1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form	f2("f2", 42, 0);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	/*try {
		Form	f3("f3", 42, 42);
		Form	f4("f4", 1, 1);

		//std::cout << f3 << f4;

		b.signForm(f3);
		std::cout << f3;
		b.signForm(f3);

		b.signForm(f4);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}*/
	return 0;
}