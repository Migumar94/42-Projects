/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:44 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/26 21:13:28 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);
		void addNumber(int n);
		template <typename Iterator> void addNumber(Iterator begin, Iterator end)
		{
			if (_vec.size() + std::distance(begin, end) > _n)
				throw TooManyNumbersException();
			_vec.insert(_vec.end(), begin, end);
		}
		int shortestSpan();
		int longestSpan();
		int getN();
		class NoSpanException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "No span to find.";
			}
		};

		class TooManyNumbersException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Too many numbers.";
			}
		};
};


#endif