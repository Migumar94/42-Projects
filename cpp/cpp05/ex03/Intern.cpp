/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:29:41 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/17 18:44:19 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::_formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *form = NULL;
	
	for(int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			switch (i)
			{
			case 0:
				form = createShrubberyCreationForm(target);
				break;
			case 1:
				form = createRobotomyRequestForm(target);
				break;
			case 2:
				form = createPresidentialPardonForm(target);
				break;
			}
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (form);
			}
		}
	throw FormNotFoundException();
}


AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found!");
}