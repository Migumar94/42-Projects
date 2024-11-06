/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:42:20 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/04 17:56:52 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	
const Animal *a = new Animal();
const Animal *d = new Dog();
const Animal *c = new Cat();
a->makeSound();
d->makeSound();
c->makeSound();
delete a;
delete d;
delete c;

const WrongAnimal *wa = new WrongAnimal();
const WrongAnimal *wc = new WrongCat();
wa->makeSound();
wc->makeSound();
delete wa;
delete wc;
}