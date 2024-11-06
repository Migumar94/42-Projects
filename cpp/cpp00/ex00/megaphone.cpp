/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:53:07 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/21 19:53:31 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void ft_mayus(char *str)
{
	int i = 0;
	char  aux;
	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			aux = str[i]+'A'-'a';
			std::cout << aux;
		}
		else
			std::cout << str[i];
		i++;
	}

}

int main (int argc , char **argv)
{
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for(int i = 1; i < argc; i++)
		{
			ft_mayus(argv[i]);
		}
	}
	std :: cout << std :: endl;
}