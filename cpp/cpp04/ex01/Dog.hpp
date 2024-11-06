/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:36:58 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 14:54:50 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();
		void makeSound() const;
		Dog(const Dog &copy);
		Dog &operator=(const Dog &assign);
};


#endif