/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:35:57 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/19 13:42:14 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>
# include <iostream>


typedef struct Data
{
	int number;
	std::string str;
} Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &src);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


#endif