/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:40:52 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/16 15:07:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{	
	public:
		MutantStack():std::stack<T>(){};
		~MutantStack(){};
		MutantStack(const MutantStack &src){
			*this = src;
		}
		MutantStack &operator=(const MutantStack &rhs){
			if (this == &rhs)
				return (*this);
			std::stack<T>::operator=(rhs);
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){
			return (std::stack<T>::c.begin());
		}
		iterator end(){
			return (std::stack<T>::c.end());
		}
	
};

#endif