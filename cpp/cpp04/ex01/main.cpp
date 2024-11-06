/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:42:20 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/04 19:27:16 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main(){

	/*const Animal* j = new Dog();

	delete j;*/
	
	Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();

	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	
	for (int i = 0; i < 10; i++)
		delete animals[i];
}