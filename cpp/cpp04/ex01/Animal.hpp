/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:37:06 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 14:59:17 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
		Animal(const Animal &copy);
		Animal &operator=(const Animal &assign);
};
#endif