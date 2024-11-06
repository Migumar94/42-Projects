/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:48 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/26 21:13:34 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_vec = rhs._vec;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_vec.size() < _n)
		_vec.push_back(n);
	else
		throw TooManyNumbersException();
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

int Span::getN()
{
	return (_n);
}