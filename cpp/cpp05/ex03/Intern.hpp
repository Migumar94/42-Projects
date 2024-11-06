/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:29:46 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/17 18:37:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	static const std::string _formNames[3];

	AForm *createShrubberyCreationForm(const std::string &target);
	AForm *createRobotomyRequestForm(const std::string &target);
	AForm *createPresidentialPardonForm(const std::string &target);
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target);

	class FormNotFoundException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

};

#endif