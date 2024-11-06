/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:31:15 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/04 17:50:12 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	void fillcontainers(char ** argv);
	void sortcontainers();
private:
	std::deque<int> dq;
	std::vector<int> vec;

};

#endif