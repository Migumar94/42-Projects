/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:26:04 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/03 16:13:17 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	double price;
	int year, month, day;
	std::stringstream date;
	std::string format="%Y-%m-%d";

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		year = std::atoi(line.substr(0, 4).c_str());
		month = std::atoi(line.substr(5, 7).c_str());
		day = std::atoi(line.substr(8, 10).c_str());
		std::tm tmDate={0,0,0,day,month-1,year-1900,0,0,0,0,0};
		if (strptime(line.substr(0, line.find(',')).c_str(), format.c_str(), &tmDate) == NULL) {
			std::cerr << "Error: Bad input => "<< line.substr(0,line.find(',')) << std::endl;
			continue;;
		}
		price = std::strtod((line.substr(line.find(',') + 1)).c_str(), NULL);
		if(price < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			break;
		}
		date << (tmDate.tm_year + 1900);
		date << '-';
		date<< (tmDate.tm_mon + 1)<< '-' << (tmDate.tm_mday);
		_offers[date.str()] = price;
		date.str("");
	}
	file.close();

}

void BitcoinExchange::calculate(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	double amount, price, total;
	int year;
	int month;
	int day;
	std::stringstream date;
	std::string format="%Y-%m-%d";

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		year = std::atoi(line.substr(0, 4).c_str());
		month = std::atoi(line.substr(5, 7).c_str());
		day = std::atoi(line.substr(8, 10).c_str());
		std::tm tmDate={0,0,0,day,month-1,year-1900,0,0,0,0,0};
		if (strptime(line.substr(0, line.find(',')).c_str(), format.c_str(), &tmDate) == NULL) {
			std::cerr << "Error: Bad input => "<< line.substr(0,line.find('|')) << std::endl;
			continue;
		}
		amount = std::strtod(line.substr(line.find('|') + 1).c_str(), NULL);
		
		date.str("");
		date << (tmDate.tm_year + 1900)<< '-'<< (tmDate.tm_mon + 1)<< '-' << (tmDate.tm_mday);
		while(_offers.find(date.str())== _offers.end())
		{
			if(tmDate.tm_year+ 1900 <2009)
			{
				std::cerr << "Error: No data available." << std::endl;
				break;
			}
			if(tmDate.tm_mday==1)
			{
				tmDate.tm_mday = 31;
				if(tmDate.tm_mon == 0)
				{
					tmDate.tm_mon = 11;
					tmDate.tm_year -= 1;
				}
				else
				{
					tmDate.tm_mon -= 1;
				}
			}
			else
			{
				tmDate.tm_mday -= 1;
			}
			date.str("");
			date << (tmDate.tm_year + 1900)<< '-'<< (tmDate.tm_mon + 1)<< '-' << (tmDate.tm_mday);
		}
		price = _offers[date.str()];

		if(amount < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if(amount > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		total = amount * price;
		std::cout <<line << " => "<< total << std::endl;
	}
	file.close();
}