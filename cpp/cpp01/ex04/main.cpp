/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:24:01 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/23 18:24:27 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void ft_replace(char *file_name, std::string content, std::string oldWord, std::string newWord)
{
	std::fstream file;
	file.open(file_name, std::ios::out);
	if(!file.is_open())
	{
		std::cout << "Error: File does not exist." << std::endl;
		return;
	}
	if(oldWord.empty())
	{
		std::cout<< "Error: Empty argument"<< std::endl;
		for(long unsigned int i = 0; i < content.length()-1; i++)
		{
			file << content[i];
		}
		file.close();
		exit(1);
	}
	for(long unsigned int i = 0; i < content.length()-1; i++)
	{
		if(content.substr(i, oldWord.length()) == oldWord)
		{
			file << newWord;
			i += oldWord.length() - 1;
		}
		else
		{
			file << content[i];
		}
	}
}

int main(int argc, char **argv)
{
	std::string content;
	std::fstream file;
	if(argc != 4)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return 1;
	}

	file.open(argv[1], std::ios::in);
	if(!file.is_open())
	{
		std::cout << "Error: File does not exist." << std::endl;
		return 1;
	}
	
	while(file.eof() == 0)
	{
		content += file.get();
	}
	file.close();
	ft_replace(argv[1], content, argv[2], argv[3]);

	return 0;	
}