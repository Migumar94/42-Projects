/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:36:58 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:00 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
class Dog : public AAnimal
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