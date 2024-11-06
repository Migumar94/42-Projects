/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:31:12 by migumar2          #+#    #+#             */
/*   Updated: 2024/10/04 17:56:49 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this == &rhs)
		return (*this);
	dq = rhs.dq;
	vec = rhs.vec;
	return (*this);
}

void PmergeMe::fillcontainers(char **argv)
{
	for(int i = 1; argv[i]; i++)
	{
		vec.push_back(atoi(argv[i]));
		dq.push_back(atoi(argv[i]));
	}
	std::cout<< "Before: ";
	for(int i = 0; i < (int)vec.size(); i++)
	{
		if(i == 6)
		{
			std::cout <<"[...]" <<std::endl;
			break;
		}
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
}

void	mergevector(std::vector<int> &vec, int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	std::vector<int> left(n1), rigth(n2);
	for(int i = 0; i < n1; i++)
		left[i] = vec[low + i];
	for(int j = 0; j < n2; j++)
		rigth[j] = vec[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = low;
	while(i < n1 && j < n2)
	{
		if(left[i] <= rigth[j])
		{
			vec[k] = left[i];
			i++;
		}
		else
		{
			vec[k] = rigth[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		vec[k] = left[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		vec[k] = rigth[j];
		j++;
		k++;
	}
}
void 	sortvector(std::vector<int> &vec, int low, int high)
{
	if(low < high)
	{
		int mid = low + (high - low) / 2;
		sortvector(vec, low, mid);
		sortvector(vec, mid + 1, high);
		mergevector(vec, low, mid, high);
	}
}

void mergeDeque(std::deque<int> &dq, int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	std::deque<int> left(n1), rigth(n2);
	for(int i = 0; i < n1; i++)
		left[i] = dq[low + i];
	for(int j = 0; j < n2; j++)
		rigth[j] = dq[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = low;
	while(i < n1 && j < n2)
	{
		if(left[i] <= rigth[j])
		{
			dq[k] = left[i];
			i++;
		}
		else
		{
			dq[k] = rigth[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		dq[k] = left[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		dq[k] = rigth[j];
		j++;
		k++;
	}
}

void sortDeque(std::deque<int> &dq, int low, int high)
{
	if(low < high)
	{
		int mid = low + (high - low) / 2;
		sortDeque(dq, low, mid);
		sortDeque(dq, mid + 1, high);
		mergeDeque(dq, low, mid, high);
	}
}

void PmergeMe::sortcontainers()
{
	clock_t start = clock();
	sortvector(vec, 0, vec.size() - 1);
	clock_t end= clock();
	std::cout<< "After: ";
	for(int i = 0; i < (int)vec.size(); i++)
	{
		if(i == 6)
		{
			std::cout <<"[...]" <<std::endl;
			break;
		}
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	clock_t elapsed = end - start;
	std::cout << "Vector sort time: " << elapsed << "us" << std::endl;
	clock_t start2 = clock();
	sortDeque(dq, 0, dq.size() - 1);
	clock_t end2 = clock();
	clock_t elapsed2 = end2 - start2;
	std::cout << "Deque sort time: " << elapsed2 << "us" << std::endl;
	
}
