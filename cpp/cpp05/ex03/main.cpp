/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:43:03 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/17 18:50:20 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat b;
	b = Bureaucrat("Bender", 1);
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	rrf->beSigned(b);
	b.executeForm(*rrf);
	return 0;
}