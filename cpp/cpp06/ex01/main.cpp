/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:35:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/19 13:34:14 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
	Data data;
	data.number = 42;
	data.str = "Hello, World!";

	uintptr_t  aux = Serializer::serialize(&data);
	std::cout << "Serialized: " << aux << std::endl;

	Data *ptr = Serializer::deserialize(aux);
	std::cout << "Deserialized: " << ptr->number << " " << ptr->str << std::endl;

}