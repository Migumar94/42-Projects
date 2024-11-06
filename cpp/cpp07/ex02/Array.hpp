/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:04:38 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/23 13:38:51 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <ctime>
# include <cstdlib>

template <typename T>
class Array {
	private:
		unsigned int _size;
		T *_array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &rhs);
		T &operator[](unsigned int n);
		unsigned int size() const;
};


template <typename T> Array<T>::Array()
{
	_size = 0;
	_array = new T[0];
}

template <typename T> Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
}

template <typename T> Array<T>::Array(const Array &src)
{
	_size = src.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T> Array<T>::~Array()
{
	delete [] _array;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
		return *this;
	delete [] _array;
	_size = rhs.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	return *this;
}

template <typename T> T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("Index out of range");
	return _array[n];
}

template <typename T> unsigned int Array<T>::size() const
{
	return _size;
}

#endif