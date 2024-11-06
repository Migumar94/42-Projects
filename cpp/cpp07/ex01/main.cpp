/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:40:26 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/19 19:42:43 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


template <typename T>void print(T &x) {
	std::cout << x << std::endl;
}

template <typename T>void plusOne(T &x) {
	x++;

}

int main() {
	int arrayInt[] = {1, 2, 3, 4, 5};
	char arrayChar[] = {'a', 'b', 'c', 'd', 'e'};
	std::string arrayString[] = {"Hello", "World", "migumar2", "esto es lioso", "bootcamp de ciber"};


	iter(arrayInt, 5, plusOne<int>);
	iter(arrayInt, 5, print<int>);
	iter(arrayChar, 5, plusOne<char>);
	iter(arrayChar, 5, print<char>);
	iter(arrayString, 5, print<std::string>);
	return 0;
}