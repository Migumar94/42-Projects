/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:09:01 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/02 21:42:44 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string filename);
		void calculate(std::string filename);
		~BitcoinExchange();
	private:
		BitcoinExchange &operator=(const BitcoinExchange &src);
		BitcoinExchange(const BitcoinExchange &src);
		std::map<std::string, double> _offers;
		BitcoinExchange();
};

#endif