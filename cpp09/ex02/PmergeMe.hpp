/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:29 by ilyanar           #+#    #+#             */
/*   Updated: 2025/03/18 00:36:51 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <math.h>
#include <cmath>
#include <utility>
#include <vector>
#include <iostream>
#include <list>
#include <unistd.h>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <sys/_pthread/_pthread_types.h>
#include <sys/_types/_pid_t.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif

class VectSort
{
	private:
		std::vector<int>	_data;
		clock_t _start;
		static int _count;
		static int _debug;
		size_t _order;
		VectSort();
		void endSortInfo() const;
		void debugCmd(char*, char**) const;
		void debugInsert(std::vector<int>&, std::vector<int>&, std::vector<int>&) const;
		void merge();
		void insert();
		void sort(std::vector<int>&, std::vector<int>&, std::vector<int>&);
	public:
		VectSort(char *);
		~VectSort();
		VectSort(const VectSort &other);
		VectSort& operator=(const VectSort &other);

		void FordJonhson();
		std::vector<long> jacobsthal(size_t) const;
		void print() const;
		void debugMode(int, int, int);
		void setDebug(int);
};

class DequeSort
{
	private:
		std::deque<int>	_data;
		clock_t _start;
		static int _count;
		static int _debug;
		size_t _order;
		DequeSort();
		void endSortInfo() const;
		void debugCmd(char*, char**) const;
		void debugInsert(std::deque<int>&, std::deque<int>&, std::deque<int>&) const;
		void merge();
		void insert();
		void sort(std::vector<int>&, std::vector<int>&, std::vector<int>&);
	public:
		DequeSort(char *);
		~DequeSort();
		DequeSort(const DequeSort &other);
		DequeSort& operator=(const DequeSort &other);

		void FordJonhson();
		void print() const;
		void debugMode(int, int, int);
		void setDebug(int);
};
#endif
