/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:10:39 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/19 19:05:27 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


	template <typename T>void iter(T *array, int length, void (*func)(T &t)){
		for (int i = 0; i < length; i++)
			func((array[i]));
	}


#endif