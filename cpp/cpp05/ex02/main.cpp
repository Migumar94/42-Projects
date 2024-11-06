/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:43:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/17 18:16:11 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	Bureaucrat	b("migumar", 1);
	Bureaucrat	c("migumar2", 150);
	std::cout << b;
	

	ShrubberyCreationForm f1= ShrubberyCreationForm("home");
	RobotomyRequestForm f2= RobotomyRequestForm("robot");
	PresidentialPardonForm f3= PresidentialPardonForm("president");
	
	try{
		b.signForm(f1);
		f1.execute(b);
		b.executeForm(f1);
	}
	catch(const std::exception &e){
		std::cerr << e.what() << '\n';
	}

	try{
		c.executeForm(f1);
	}catch(const std::exception &e){
		std::cerr << e.what() << '\n';
	}

	try
	{
		b.signForm(f2);
		f2.execute(b);
		b.executeForm(f2);
		b.executeForm(f2);
		b.executeForm(f2);
		b.executeForm(f2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		c.executeForm(f2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		b.signForm(f3);
		f3.execute(b);
		b.executeForm(f3);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		c.executeForm(f3);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}