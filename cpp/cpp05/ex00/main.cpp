/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:43:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/15 15:42:53 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat b("Migumar", 150);
		std::cout << b << std::endl;
		//b.decrementGrade();
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat b1("Migumar1", 1);
		//b1.incrementGrade();
		std::cout << b1 << std::endl;

	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}


	 try{
		Bureaucrat b2("Migumar2", 151);
		std::cout << b2 << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat b3("Migumar3", 0);
		std::cout << b3 << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}