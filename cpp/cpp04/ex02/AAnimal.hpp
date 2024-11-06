/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:37:06 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 16:30:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &assign);
};
#endif