/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:09:32 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/09 14:43:22 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string *_ideas;
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &assign);
};

#endif
