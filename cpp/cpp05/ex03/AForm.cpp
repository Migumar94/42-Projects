/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:44:44 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/17 13:46:15 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

const std::string &AForm::getName() const
{
	return (_name);
}

bool::AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooHighException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

const char *AForm::FileNotOpenException::what() const throw()
{
	return ("File could not be opened!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << ", form sign grade " << form.getSignGrade() << ", form exec grade " << form.getExecGrade() << ", form is ";
	if (form.getSigned())
		out << "signed.";
	else
		out << "not signed.";
	return (out);
}
