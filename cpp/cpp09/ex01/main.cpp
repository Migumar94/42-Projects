/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:15:25 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	int i = 0;
	int num1;
	int num2;
	if(argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	RPN rpn;
	std::string str = argv[1];
	while(str[i])
	{
		if(str[i] == ' ')
		{
			i++;
			continue;
		}
		else if(isdigit(str[i]))
		{
			rpn.push(str[i] - '0');
			if(str[i+1]!= '\0' && str[i+1] != ' ')
			{
				std::cerr << "Error: Invalid expression" << std::endl;
				return (1);
			}
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			num2 = rpn.pop();
			num1 = rpn.pop();
			rpn.push(rpn.calculate(num1, num2, str[i]));
			if( str[i+1]!= '\0' && str[i+1] != ' ')
			{
				std::cerr << "Error: Invalid expression" << std::endl;
				return (1);
			}
		}
		else
		{
			std::cerr << "Error: Invalid character" << std::endl;
			return (1);
		}
		i++;
	}
	if (rpn.getSize() != 1)
	{
		std::cerr << "Error: Invalid expression" << std::endl;
		return (1);
	}
		std::cout << rpn.pop() << std::endl;
	
}