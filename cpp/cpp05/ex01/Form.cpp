/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:44:44 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/15 19:22:40 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooHighException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form sign grade " << form.getSignGrade() << ", form exec grade " << form.getExecGrade() << ", form is ";
	if (form.getSigned())
		out << "signed.";
	else
		out << "not signed.";
	return (out);
}
