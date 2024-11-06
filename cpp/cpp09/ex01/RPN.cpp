/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:15:16 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/03 16:50:53 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : numbers()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src) : numbers(src.numbers)
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this == &src)
		return (*this);
	numbers = src.numbers;
	return (*this);
}

void RPN::push(int num)
{
	numbers.push(num);
}

int RPN::pop()
{
	
	if (numbers.empty())
	{
		std::cerr << "Error: Stack is empty" << std::endl;
		exit(1);
	}
	int num = numbers.top();
	numbers.pop();
	return (num);
}

int RPN::calculate(int num1, int num2, char op)
{
	if (op == '+')
		return (num1 + num2);
	else if (op == '-')
		return (num1 - num2);
	else if (op == '*')
		return (num1 * num2);
	else if (op == '/')
	{
		if (num2 == 0)
		{
			std::cerr << "Error: Division by zero" << std::endl;
			exit(1);
		}
		return (num1 / num2);		
	}
	std::cerr << "Error" << std::endl;
	exit(1);
}

int RPN::getSize()
{
	return (numbers.size());
}