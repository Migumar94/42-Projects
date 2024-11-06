/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:38:55 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/26 13:27:17 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ElementNotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Element not found";
	}
};

template <typename T> int easyfind(T container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw ElementNotFoundException();
	return *it;
}

#endif