/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:44:47 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/17 16:17:25 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP


# include <iostream>
# include <string>
# include <stdexcept>
#include <cstdlib> 
#include <ctime>
#include "Bureaucrat.hpp"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
public:
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	~AForm();
	AForm(const AForm &copy);
	AForm &operator=(const AForm &other);

	const std::string &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class FileNotOpenException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);



#endif